#include "Component.h"
void Component::OnAttached()
{
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
    OnDestroyed_Internal();
    // Call c# OnDestroyed
}
