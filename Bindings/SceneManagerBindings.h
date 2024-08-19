#pragma once
#include <cstdint>

extern "C" __declspec(dllexport) void RequestSceneLoad(intptr_t requestPtr);
extern "C" __declspec(dllexport) intptr_t ForceSceneLoad(int* instanceId);
