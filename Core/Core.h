#pragma once
#include <SDL.h>

class Core {
public:
    static void Init(intptr_t onGameInitialized);
    static void Shutdown();

    static void GameLoop();

    static bool quit;
    
    static SDL_Window* window;
    static SDL_Renderer* renderer;

    typedef void (*CoreDelegate)();
    
    static bool displayFps; 

    static void SetTargetFrameRate(int frameRate);
    static void LimitFrameRate(bool value);
    
private:
    static float timestepInSec;
    static bool limitFrameRate;
};
