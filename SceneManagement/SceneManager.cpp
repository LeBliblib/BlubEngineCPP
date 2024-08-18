#include "SceneManager.h"

std::unique_ptr<Scene> SceneManager::activeScene{};

void SceneManager::LoadNewScene()
{
    if (activeScene != nullptr)
    {
        activeScene->Destroy();
    }
    
    activeScene = std::make_unique<Scene>();

//    *instanceID = activeScene->GetInstanceId();
//    return activeScene->GetIntPtr();
}
