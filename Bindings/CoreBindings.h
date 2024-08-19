#pragma once
#include <cstdint>

extern "C" __declspec(dllexport) void InitGame(intptr_t onGameInitialized);

extern "C" __declspec(dllexport) void SetTargetFrameRate(int frameRate);
extern "C" __declspec(dllexport) void LimitFrameRate(bool value);

extern "C" __declspec(dllexport) void DisplayFps(bool value);