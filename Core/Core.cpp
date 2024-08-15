#include <memory>
#include <utility>
#include "Core.h"

#include <iostream>

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
        Core::init(path);
        return 0;
    }
}

void Core::init(const std::string_view path) {
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

    {
        Scene scene = Scene();
        SceneObject* sceneObject = scene.CreateSceneObject();
        auto textureRenderer = sceneObject->AddComponent<TextureRenderer>();
        textureRenderer->SetTexture(texture);
        textureRenderer->SetSortingLayer(0);

        sceneObject->GetTransform()->position = {0.0f, 0.0f};

        SceneObject* sceneObject2 = scene.CreateSceneObject();
        auto camera = sceneObject2->AddComponent<Camera>();
        camera->orthographicSize = 1;
        camera->SetPriority(1);
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        RenderLoop::Render();
    }

    std::cout << "out of scope\n";
    
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Core::shutdown() {
    //Quit and cleanup everything
}