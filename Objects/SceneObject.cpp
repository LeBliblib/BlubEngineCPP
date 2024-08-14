#include "SceneObject.h"

#include <iostream>

SceneObject::SceneObject()
{
    transform = std::make_unique<Transform>(this);
}

SceneObject::~SceneObject()
{
    std::cout << "SceneObject destroyed" << '\n';
}
