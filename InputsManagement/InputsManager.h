#pragma once
#include <SDL_keycode.h>
#include <unordered_set>

class InputsManager
{
public:
    static void HandleEvents(bool &quit);

    static bool IsKeyDown(SDL_Keycode key);
    static bool IsKeyPressed(SDL_Keycode key);
    static bool IsKeyUp(SDL_Keycode key);

private:
    static std::pmr::unordered_set<SDL_Keycode> downKeys;
    static std::pmr::unordered_set<SDL_Keycode> pressedKeys;
    static std::pmr::unordered_set<SDL_Keycode> upKeys;
};
