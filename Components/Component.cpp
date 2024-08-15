#include "Component.h"

#include "UpdateLoop.h"

void Component::OnAttached()
{
    UpdateLoop::Register(this);
    OnAttached_Internal();
    // Call c# OnAttached
}
void Component::OnInitialized()
{
    OnInitialized_Internal();
    // Call c# OnInitialized
}
void Component::OnUpdate()
{
    OnUpdate_Internal();
    // Call c# OnUpdate
}
void Component::OnDestroyed()
{
    UpdateLoop::Unregister(GetInstanceId());
    OnDestroyed_Internal();
    // Call c# OnDestroyed
}

void Component::Destroy()
{
    OnDestroyed();
}
