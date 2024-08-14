#include "EngineObject.h"

int EngineObject::instanceCounter = 0;

intptr_t EngineObject::GetIntPtr() const
{
    return reinterpret_cast<intptr_t>(this);
}
