#pragma once
#include "Component.h"

class DefaultComponent final : public Component
{
public:
    DefaultComponent() = delete;

    explicit DefaultComponent(SceneObject* obj)
        : Component(obj) {}

    ~DefaultComponent() override;
    
    void OnAttached_Internal() override;
    void OnInitialized_Internal() override;
    void OnUpdate_Internal() override;
    void OnDestroyed_Internal() override;
};
