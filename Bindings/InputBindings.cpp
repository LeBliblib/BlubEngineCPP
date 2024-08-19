#include "InputBindings.h"

#include "../InputsManagement/InputsManager.h"
#include "../InputsManagement/Keycode.h"

bool IsKeyDown(const int key)
{
    return InputsManager::IsKeyDown(Keycode::ToSdl(key));
}

bool IsKeyPressed(const int key)
{
    return InputsManager::IsKeyPressed(Keycode::ToSdl(key));
}

bool IsKeyUp(const int key)
{
    return InputsManager::IsKeyUp(Keycode::ToSdl(key));
}
