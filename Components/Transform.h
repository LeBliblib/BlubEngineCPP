#pragma once

#include "Component.h"
#include "../Maths/Vector2.h"

class Transform final : public Component {
public:
    Transform() = delete;
    explicit Transform(SceneObject* obj) : Component(obj)
    {
        scale = {1, 1};
    }
~Transform() override;
    
    Vector2 position{};
    float rotation{};
    Vector2 scale{};

    void SetPosition(const Vector2& pos);
    void SetRotation(float rot);
    void SetScale(const Vector2& s);
    
    void OnAttached_Internal() override;
    void OnInitialized_Internal() override;
    void OnUpdate_Internal() override;
    void OnDestroyed_Internal() override;
};