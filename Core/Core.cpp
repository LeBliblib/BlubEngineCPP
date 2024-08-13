#include <memory>
#include <utility>
#include "Core.h"

#include <iostream>

#include "../AssetsManagement//AssetManager.h"
#include "../Components/TextureRenderer.h"
#include "../Rendering/RenderLoop.h"

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
    window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
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
        Transform transform = Transform();
        TextureRenderer textureRenderer = TextureRenderer(nullptr, texture, 0);

        RenderLoop::Register(&textureRenderer);

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