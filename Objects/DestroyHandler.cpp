#include "DestroyHandler.h"

std::unordered_map<int, SceneObject*> DestroyHandler::destroyQueue;
DestroyHandler::DestroyCallbackDelegate DestroyHandler::destroyCallback;

void DestroyHandler::SetDestroyCallback(const intptr_t callbackPtr)
{
    try
    {
        SetDestroyCallback(reinterpret_cast<DestroyCallbackDelegate>(callbackPtr));  // NOLINT(performance-no-int-to-ptr)
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void DestroyHandler::SetDestroyCallback(const DestroyCallbackDelegate callback)
{
    destroyCallback = callback;
}

void DestroyHandler::RequestDestroy(SceneObject* obj)
{
    if(destroyQueue.contains(obj->GetInstanceId()))
    {
        std::cerr << "Object with id: " << obj->GetInstanceId() << " is already in the destroy queue\n";
        return;
    }
    
    destroyQueue[obj->GetInstanceId()] = obj;
}

void DestroyHandler::OnFrameStart()
{
    for (const auto [fst, snd] : destroyQueue)
    {
        snd->Destroy();
        destroyCallback(fst);
    }

    destroyQueue.clear();
}
