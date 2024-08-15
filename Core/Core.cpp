#include <memory>
#include <utility>
#include "Core.h"

#include <chrono>
#include <iostream>

#include "../AssetsManagement//AssetManager.h"
#include "../Components/Camera.h"
#include "../Components/TextureRenderer.h"
#include "../Objects/SceneObject.h"
#include "../Rendering/RenderLoop.h"
#include "../SceneManagement/Scene.h"

SDL_Window* Core::window = nullptr;
SDL_Renderer* Core::renderer = nullptr;

using namespace std::chrono_literals;

// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

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

void Core::GameLoop()
{
    using clock = std::chrono::high_resolution_clock;

    std::chrono::nanoseconds lag(0ns);
    auto time_start = clock::now();
    
    while(!quit)
    {
        auto delta_time = clock::now() - time_start;
        time_start = clock::now();
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
        
        HandleEvents();

        // update game logic as lag permits
        while(lag >= timestep) {
            lag -= timestep;

            auto secondsDelta = std::chrono::duration_cast<std::chrono::duration<float>>(timestep).count();
            std::cout << "time: " << secondsDelta << '\n';
            Camera::mainCamera->sceneObject->GetTransform()->position.x += 0.5f * secondsDelta;
        }

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
