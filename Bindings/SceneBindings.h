#pragma once
#include <cstdint>

extern "C" __declspec(dllexport) intptr_t CreateSceneObject(int* instanceId, intptr_t* transformPtr, int* transformId);
