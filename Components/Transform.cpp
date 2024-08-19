#include "Transform.h"

#include <iostream>

Transform::~Transform()
{
    std::cout << "Transform destroyed" << '\n';
}

void Transform::SetPosition(const Vector2& pos) {
    position = pos;
}

void Transform::SetRotation(float rot) {
    rotation = rot;
}

void Transform::SetScale(const Vector2& s) {
    scale = s;
}

void Transform::OnAttached_Internal() {}
void Transform::OnInitialized_Internal() {}
void Transform::OnUpdate_Internal()
{
}
void Transform::OnDestroyed_Internal() {}
