#pragma once
#include <unordered_map>

class Component;

class UpdateLoop
{
public:
    static void Update();
    static void Register(Component* component);
    static void Unregister(int instanceId);

private:
    static std::unordered_map<int, Component*> components;
};
