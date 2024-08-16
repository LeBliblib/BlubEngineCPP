#include "SceneObject.h"
#include "../SceneManagement/Scene.h"

#include <iostream>
#include <ranges>

SceneObject::~SceneObject()
{
    std::cout << "SceneObject destroyed" << '\n';
}

void SceneObject::Destroy()
{
    if(scene != nullptr)
        scene->UnregisterSceneObject(GetInstanceId());
    
    transform->Destroy();
    for (const auto& val : components | std::views::values)
    {
        val->Destroy();
    }
}
