#pragma once
#include <cstdint>

#include "../Maths/Vector2.h"

extern "C" __declspec(dllexport) void SetPriority(intptr_t cameraPtr, int priority);
extern "C" __declspec(dllexport) int GetPriority(intptr_t cameraPtr);

extern "C" __declspec(dllexport) void SetOrthographicSize(intptr_t cameraPtr, float size);
extern "C" __declspec(dllexport) float GetOrthographicSize(intptr_t cameraPtr);

extern "C" __declspec(dllexport) void WorldToScreenPoint(intptr_t cameraPtr, Vector2 worldPoint, const Vector2Int* screenPoint);
