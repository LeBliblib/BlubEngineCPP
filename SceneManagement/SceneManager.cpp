#include "SceneManager.h"

std::unique_ptr<Scene> SceneManager::activeScene{};
SceneManager::SceneLoadDelegate SceneManager::sceneLoadRequest{};
bool SceneManager::sceneLoadRequested{};

void SceneManager::RequestSceneLoad(const intptr_t requestPtr)
{
    try
    {
        sceneLoadRequest = reinterpret_cast<SceneLoadDelegate>(requestPtr);  // NOLINT(performance-no-int-to-ptr)
        sceneLoadRequested = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while setting the scene load request delegate. \n" << e.what() << '\n';
    }
}

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

intptr_t SceneManager::ForceSceneLoad(int* instanceId)
{
    LoadNewScene();

    *instanceId = activeScene->GetInstanceId();
    return activeScene->GetIntPtr();
}

void SceneManager::OnFrameStart()
{
    if (!sceneLoadRequested) return;

    LoadNewScene();

    if(activeScene == nullptr)
    {
        std::cerr << "Failed to create a blank new scene. \n";
        return;
    }
    
    sceneLoadRequest(activeScene->GetIntPtr(), activeScene->GetInstanceId());

    sceneLoadRequested = false;
    sceneLoadRequest = nullptr;
}
