#include "DefaultComponent.h"

#include <iostream>

DefaultComponent::~DefaultComponent()
{
    std::cout << "DefaultComponent destroyed" << '\n';
}

void DefaultComponent::OnAttached_Internal() {}
void DefaultComponent::OnInitialized_Internal() {}
void DefaultComponent::OnUpdate_Internal()
{
}
void DefaultComponent::OnDestroyed_Internal()
{
}
