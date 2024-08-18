#pragma once

#include <unordered_map>

#include "../Objects/EngineObject.h"

class SceneObject;

enum class EVENT_METHOD_TYPE
{
    ATTACHED = 0,
    INITIALIZED = 1,
    UPDATE = 2,
    DESTROYED = 3
};

enum class BUILT_IN_TYPES
{
    NONE = 0,
    CAMERA = 1,
    TEXTURE_RENDERER = 2,
    TRANSFORM = 3
};

class Component : public EngineObject
{
public:
    Component() = delete;
    explicit Component(SceneObject* obj) : sceneObject(obj) { }
    
    void OnAttached();
    virtual void OnAttached_Internal() = 0;
    
    void OnInitialized();
    virtual void OnInitialized_Internal() = 0;

    void OnUpdate();
    virtual void OnUpdate_Internal() = 0;
    
    void OnDestroyed();
    virtual void OnDestroyed_Internal() = 0;
    
    void Destroy() override;
    
    void AddEventMethod(EVENT_METHOD_TYPE type, intptr_t eventMethodPtr);

    SceneObject* sceneObject{};

private:
    typedef void (*EventDelegate)();
    std::unordered_map<EVENT_METHOD_TYPE, EventDelegate> eventMethods{};
};
