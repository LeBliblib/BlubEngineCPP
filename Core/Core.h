#pragma once
#include <SDL.h>
#include <string>

class Core {
public:
    static void Init(std::string_view path);
    static void Shutdown();

    static void GameLoop();

    static bool quit;
    
    static SDL_Window* window;
    static SDL_Renderer* renderer;

};
