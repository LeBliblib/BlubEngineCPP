#pragma once
#include <cstdint>
#include <iostream>

class EngineObject
{
public:
    EngineObject()
    {
        instanceId = GetNextInstanceId();
    }

    virtual ~EngineObject() = default;

    virtual void Destroy() = 0;
    
    [[nodiscard]] intptr_t GetIntPtr() const;

    [[nodiscard]] int GetInstanceId() const
    {
        return instanceId;
    }

private:
    int instanceId{};

    static int instanceCounter;
    static int GetNextInstanceId() { return instanceCounter++; }
};
