#include <memory>
#include "Core.h"

#include <chrono>
#include <iostream>

#include "../AssetsManagement/AssetManager.h"
#include "../Loops/UpdateLoop.h"
#include "../InputsManagement/InputsManager.h"
#include "../Objects/DestroyHandler.h"
#include "../Rendering/RenderLoop.h"
#include "../SceneManagement/SceneManager.h"
#include "../TimeManagement/Time.h"

SDL_Window* Core::window = nullptr;
SDL_Renderer* Core::renderer = nullptr;

void Core::Init(intptr_t onGameInitialized) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Tinity Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CoreDelegate onGameInitializedDelegate = nullptr;
    
    try
    {
        onGameInitializedDelegate = reinterpret_cast<CoreDelegate>(onGameInitialized);  // NOLINT(performance-no-int-to-ptr)
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while setting onGameInitialized delegate. \n" << e.what() << '\n';
    }
    
    RenderLoop::Init();
    AssetManager::Init();

    onGameInitializedDelegate();
    
    GameLoop();
    
    Shutdown();
}

void Core::Shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Core::quit{};

const float NANO_TO_SEC = 1.0f / 1e9f;
float Core::timestepInSec = 1.0f / 60.0f;
bool Core::limitFrameRate = true;

bool Core::displayFps = false;

void preciseSleep(double seconds) {
    using namespace std;
    using namespace std::chrono;

    static double estimate = 5e-3;
    static double mean = 5e-3;
    static double m2 = 0;
    static int64_t count = 1;

    while (seconds > estimate) {
        auto start = high_resolution_clock::now();
        this_thread::sleep_for(milliseconds(1));
        auto end = high_resolution_clock::now();

        double observed = (end - start).count() * NANO_TO_SEC;
        seconds -= observed;

        ++count;
        double delta = observed - mean;
        mean += delta / count;
        m2   += delta * (observed - mean);
        double stddev = sqrt(m2 / (count - 1));
        estimate = mean + stddev;
    }

    // spin lock
    auto start = high_resolution_clock::now();
    while ((high_resolution_clock::now() - start).count() * NANO_TO_SEC < seconds);
}

void OnFrameStart()
{
    SceneManager::OnFrameStart();
    DestroyHandler::OnFrameStart();
}

void Core::GameLoop()
{
    using clock = std::chrono::high_resolution_clock;
    auto time_start = clock::now();
    
    while(!quit)
    {
        auto deltaTime = static_cast<float>((clock::now() - time_start).count()) * NANO_TO_SEC;
        
        if(limitFrameRate && deltaTime < timestepInSec) {
            const auto diff = timestepInSec - deltaTime;
            
            preciseSleep(diff);
            
            deltaTime = static_cast<float>((clock::now() - time_start).count()) * NANO_TO_SEC;
            //std::cout << "delta_time: " << delta_time << '\n';
        }

        Time::SetDeltaTime(deltaTime);
        if (displayFps) std::cout << "delta_time: " << deltaTime << " FPS: " << 1 / deltaTime << '\n';
        
        time_start = clock::now();

        OnFrameStart();
        
        InputsManager::HandleEvents(quit);

        UpdateLoop::Update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        RenderLoop::Render();
        SDL_RenderPresent(renderer); 
    }
}

void Core::SetTargetFrameRate(const int frameRate)
{
    timestepInSec = 1.0f / static_cast<float>(frameRate);
}

void Core::LimitFrameRate(bool value)
{
    limitFrameRate = value;
}

