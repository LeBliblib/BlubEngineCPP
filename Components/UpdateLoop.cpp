#include "UpdateLoop.h"

#include <iostream>

#include "Component.h"

#include <ranges>

std::unordered_map<int, Component*> UpdateLoop::components{};

void UpdateLoop::Update()
{
    for (const auto& val : components | std::views::values)
    {
        val->OnUpdate();
    }
}

void UpdateLoop::Register(Component* component)
{
    std::cout << "Registering component with instance id: " << component->GetInstanceId() << '\n';
    
    components[component->GetInstanceId()] = component;
}

void UpdateLoop::Unregister(const int instanceId)
{
    std::cout << "Unregistering component with instance id: " << instanceId << '\n';
    
    if (components.contains(instanceId))
    {
        components.erase(instanceId);
    }
}
