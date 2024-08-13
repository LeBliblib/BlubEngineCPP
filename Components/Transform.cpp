#include "Transform.h"

#include <iostream>

Transform::~Transform()
{
    std::cout << "Destroying Transform\n";
}

void Transform::setPosition(const Vector2& pos) {
    position = pos;
}

void Transform::setRotation(float rot) {
    rotation = rot;
}

void Transform::setScale(const Vector2& s) {
    scale = s;
}