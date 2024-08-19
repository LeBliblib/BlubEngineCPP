#pragma once
#include <cstdint>


extern "C" __declspec(dllexport) bool DestroySceneObject(intptr_t sceneObjectPtr);

extern "C" __declspec(dllexport) void SetDestroyHandlerCallback(intptr_t callbackPtr);

extern "C" __declspec(dllexport) bool AddComponent(intptr_t sceneObjectPtr, int componentType, const intptr_t* eventMethodPtrs,
    int* eventMethodsType, int eventMethodCount, intptr_t* componentPtr, int* instanceId);

extern "C" __declspec(dllexport) bool RemoveComponent(intptr_t sceneObjectPtr, int componentId);
