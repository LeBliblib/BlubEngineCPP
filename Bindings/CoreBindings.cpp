#include "CoreBindings.h"

#include <iostream>

#include "../Components/Camera.h"
#include "../Core/Core.h"
#include "../Objects/SceneObject.h"


extern "C" {
    __declspec(dllexport) void InitGame(intptr_t onGameInitialized) {
        Core::Init(onGameInitialized);
    }
}

extern "C" {
    __declspec(dllexport)
    intptr_t AAA()
    {
        return Camera::mainCamera->sceneObject->GetTransform()->GetIntPtr();
    }
}

void SetTargetFrameRate(const int frameRate)
{
    Core::SetTargetFrameRate(frameRate);
}

void LimitFrameRate(const bool value)
{
    Core::LimitFrameRate(value);
}

void DisplayFps(const bool value)
{
    Core::displayFps = value;
}
