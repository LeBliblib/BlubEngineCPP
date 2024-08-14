#pragma once
#include <cstdint>

class EngineObject
{
public:
    EngineObject()
    {
        instanceId = GetNextInstanceId();
    }

    virtual ~EngineObject() = default;
    
    [[nodiscard]] intptr_t GetIntPtr() const;

    int instanceId{};

private:
    static int instanceCounter;
    static int GetNextInstanceId() { return instanceCounter++; }
};
