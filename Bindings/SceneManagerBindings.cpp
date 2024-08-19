#include "SceneManagerBindings.h"

#include "../SceneManagement/SceneManager.h"

extern "C" __declspec(dllexport) void RequestSceneLoad(const intptr_t requestPtr)
{
    SceneManager::RequestSceneLoad(requestPtr);
}

extern "C" __declspec(dllexport) intptr_t ForceSceneLoad(int* instanceId)
{
    return SceneManager::ForceSceneLoad(instanceId);
}
