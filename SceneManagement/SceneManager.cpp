#include "SceneManager.h"

std::unique_ptr<Scene> SceneManager::activeScene{};

intptr_t SceneManager::LoadNewScene(int* instanceID)
{
    if (activeScene != nullptr)
    {
        activeScene->Destroy();
    }
    
    activeScene = std::make_unique<Scene>();

    *instanceID = activeScene->GetInstanceId();
    return activeScene->GetIntPtr();
}
