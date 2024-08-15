#include <memory>
#include "Core.h"

#include <chrono>

#include "../AssetsManagement//AssetManager.h"
#include "../Components/Camera.h"
#include "../Components/TextureRenderer.h"
#include "../Objects/SceneObject.h"
#include "../Rendering/RenderLoop.h"
#include "../SceneManagement/Scene.h"

SDL_Window* Core::window = nullptr;
SDL_Renderer* Core::renderer = nullptr;

extern "C" {
     __declspec(dllexport) int initWrapper(const char* path) {
        Core::Init(path);
        return 0;
    }
}

void Core::Init(const std::string_view path) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    RenderLoop::Init();
    AssetManager::init();

    auto texture = AssetManager::loadTexture(path);
    if(texture == nullptr) {
        SDL_Delay(3000);

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
        
    Scene scene = Scene();
    SceneObject* sceneObject = scene.CreateSceneObject();
    auto textureRenderer = sceneObject->AddComponent<TextureRenderer>();
    textureRenderer->SetTexture(texture);
    textureRenderer->SetSortingLayer(0);

    SceneObject* sceneObject2 = scene.CreateSceneObject();
    auto camera = sceneObject2->AddComponent<Camera>();
    camera->orthographicSize = 1;
    camera->SetPriority(1);
    
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
const float TIMESTEP_IN_SEC = 1.0f / 60.0f;

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



void Core::GameLoop()
{
    using clock = std::chrono::high_resolution_clock;
    auto time_start = clock::now();
    
    while(!quit)
    {
        auto delta_time = static_cast<float>((clock::now() - time_start).count()) * NANO_TO_SEC;
        
        if(delta_time < TIMESTEP_IN_SEC) {
            const auto diff = TIMESTEP_IN_SEC - delta_time;
            
            preciseSleep(diff);
            
            delta_time = static_cast<float>((clock::now() - time_start).count()) * NANO_TO_SEC;
            //std::cout << "delta_time: " << delta_time << '\n';
        }
        
        time_start = clock::now();
     
        HandleEvents();
        
        Camera::mainCamera->sceneObject->GetTransform()->position.x += 0.5f * delta_time;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        RenderLoop::Render();
        SDL_RenderPresent(renderer); 
    }
}


void Core::HandleEvents()
{
    SDL_Event e;
    while (!quit && SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            default: ;
        }
    }
}
