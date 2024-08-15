#pragma once

class Time
{
public:
    static float GetDeltaTime() { return deltaTime; }
    static void SetDeltaTime(const float value) { deltaTime = value; }
    
private:
    static float deltaTime;
};
