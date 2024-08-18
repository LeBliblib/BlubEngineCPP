#include "SceneBindings.h"

#include "../SceneManagement/SceneManager.h"
#include "../SceneManagement/Scene.h"

intptr_t CreateSceneObject(int* instanceId)
{
    const auto scene = SceneManager::GetActiveScene();
    const auto object = scene->CreateSceneObject();
    
    *instanceId = object->GetInstanceId();
    return reinterpret_cast<intptr_t>(object);
}