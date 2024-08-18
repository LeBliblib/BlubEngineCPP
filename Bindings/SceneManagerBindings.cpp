#include "SceneManagerBindings.h"

#include "../SceneManagement/SceneManager.h"

extern "C" __declspec(dllexport) intptr_t LoadNewScene(int* instanceID)
{
    SceneManager::LoadNewScene();
    
    const auto scene = SceneManager::GetActiveScene();
    
    *instanceID = scene->GetInstanceId();
    return scene->GetIntPtr();
}
