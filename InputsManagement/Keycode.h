#pragma once
#include <SDL_keycode.h>

class Keycode
{
public:
    static SDL_Keycode ToSdl(int key);
};
