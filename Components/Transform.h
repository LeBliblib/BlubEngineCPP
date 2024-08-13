#pragma once

#include "Component.h"
#include "../Maths/Vector2.h"

class Transform : Component {
public:
    Vector2 position{};
    float rotation{};
    Vector2 scale{};

    Transform() = default;
    ~Transform();

    void setPosition(const Vector2& pos);
    void setRotation(float rot);
    void setScale(const Vector2& s);
};