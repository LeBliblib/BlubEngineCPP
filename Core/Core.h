#pragma once
#include <SDL.h>
#include <string>

class Core {
public:
    static void init(std::string_view path);
    static void shutdown();

    static SDL_Window* window;
    static SDL_Renderer* renderer;

};
