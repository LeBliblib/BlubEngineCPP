#include "Component.h"

#include <iostream>

#include "UpdateLoop.h"

void Component::OnAttached()
{
    UpdateLoop::Register(this);
    OnAttached_Internal();

    std::cout << "Component attached" << '\n';

    // On attached is called directly by c# scripting backend
}
void Component::OnInitialized()
{
    OnInitialized_Internal();

    if(eventMethods.contains(EVENT_METHOD_TYPE::INITIALIZED))
    {
        eventMethods[EVENT_METHOD_TYPE::INITIALIZED]();
    }
}
void Component::OnUpdate()
{
    OnUpdate_Internal();
    
    if(eventMethods.contains(EVENT_METHOD_TYPE::UPDATE))
    {
        eventMethods[EVENT_METHOD_TYPE::UPDATE]();
    }
}
void Component::OnDestroyed()
{
    UpdateLoop::Unregister(GetInstanceId());
    OnDestroyed_Internal();

    if(eventMethods.contains(EVENT_METHOD_TYPE::DESTROYED))
    {
        eventMethods[EVENT_METHOD_TYPE::DESTROYED]();
    }
}

void Component::Destroy()
{
    OnDestroyed();
}

void Component::AddEventMethod(EVENT_METHOD_TYPE type, const intptr_t eventMethodPtr)
{
    try
    {
        eventMethods[type] = reinterpret_cast<EventDelegate>(eventMethodPtr);  // NOLINT(performance-no-int-to-ptr)
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while adding an event method to the component. \n" << e.what() << '\n';
    }
}
