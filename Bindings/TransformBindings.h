#pragma once
#include <cstdint>

#include "../Maths/Vector2.h"

extern "C" __declspec(dllexport) void GetPosition(intptr_t transformPtr, Vector2* position);
extern "C" __declspec(dllexport) void SetPosition(intptr_t transformPtr, const Vector2* position);

extern "C" __declspec(dllexport) float GetRotation(intptr_t transformPtr);
extern "C" __declspec(dllexport) void SetRotation(intptr_t transformPtr, float rotation);

extern "C" __declspec(dllexport) void GetScale(intptr_t transformPtr, Vector2* scale);
extern "C" __declspec(dllexport) void SetScale(intptr_t transformPtr, const Vector2* scale);
