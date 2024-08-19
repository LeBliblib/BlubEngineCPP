#include "InputsManager.h"

#include <SDL_events.h>

std::pmr::unordered_set<SDL_Keycode> InputsManager::downKeys{};
std::pmr::unordered_set<SDL_Keycode> InputsManager::pressedKeys{};
std::pmr::unordered_set<SDL_Keycode> InputsManager::upKeys{};

void InputsManager::HandleEvents(bool &quit)
{
    downKeys.clear();
    upKeys.clear();
    
    SDL_Event e;
    while (!quit && SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                if (!pressedKeys.contains(e.key.keysym.sym))
                {
                    pressedKeys.insert(e.key.keysym.sym);
                    downKeys.insert(e.key.keysym.sym);
                }
                break;
            case SDL_KEYUP:
                if (pressedKeys.contains(e.key.keysym.sym))
                {
                    pressedKeys.erase(e.key.keysym.sym);
                    upKeys.insert(e.key.keysym.sym);
                }
                break;
            default: ;
        }
    }
}

bool InputsManager::IsKeyDown(const SDL_Keycode key)
{
    return downKeys.contains(key);
}

bool InputsManager::IsKeyPressed(const SDL_Keycode key)
{
    return pressedKeys.contains(key);
}

bool InputsManager::IsKeyUp(const SDL_Keycode key)
{
    return upKeys.contains(key);
}
