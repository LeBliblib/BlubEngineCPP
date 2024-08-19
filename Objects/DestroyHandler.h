#pragma once
#include "SceneObject.h"

class DestroyHandler
{
private:
    typedef void (*DestroyCallbackDelegate)(int);
    static DestroyCallbackDelegate destroyCallback;

public:
    static void SetDestroyCallback(intptr_t callbackPtr);
    static void SetDestroyCallback(DestroyCallbackDelegate callback);

    static void RequestDestroy(SceneObject* obj);

    static void OnFrameStart();
    
    static std::unordered_map<int, SceneObject*> destroyQueue;
};
