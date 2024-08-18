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
