#include "SceneBindings.h"

#include "../SceneManagement/SceneManager.h"
#include "../SceneManagement/Scene.h"

extern "C" __declspec(dllexport) intptr_t CreateSceneObject(int* instanceId, intptr_t* transformPtr, int* transformId)
{
    const auto scene = SceneManager::GetActiveScene();
    const auto object = scene->CreateSceneObject();
    
    *instanceId = object->GetInstanceId();

    const auto transform = object->GetTransform();
    
    *transformPtr = transform->GetIntPtr();
    *transformId = transform->GetInstanceId();
    return reinterpret_cast<intptr_t>(object);
}