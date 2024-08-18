#pragma once
#include <cstdint>

#include "../Objects/SceneObject.h"

class Marshal
{
public:
    static Transform* UnmarshalTransform(intptr_t transformPtr);
    static SceneObject* UnmarshalSceneObject(intptr_t sceneObjectPtr);
};
