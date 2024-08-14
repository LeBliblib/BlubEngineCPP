#pragma once

#include "../Objects/EngineObject.h"

class SceneObject;

class Component : public EngineObject
{
public:
    Component() = delete;
    explicit Component(SceneObject* obj) : sceneObject(obj) {}
    
    void OnAttached();
    virtual void OnAttached_Internal() = 0;
    
    void OnInitialized();
    virtual void OnInitialized_Internal() = 0;

    void OnUpdate();
    virtual void OnUpdate_Internal() = 0;
    
    void OnDestroyed();
    virtual void OnDestroyed_Internal() = 0;
    
    SceneObject* sceneObject{};
};
