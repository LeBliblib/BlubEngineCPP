#include "Scene.h"

#include <iostream>
#include <ranges>

Scene::~Scene()
{
    std::cout << "Scene destroyed" << '\n';
}

void Scene::Destroy()
{
    for (const auto& val : sceneObjects | std::views::values)
    {
        val->Destroy();
    }
}
