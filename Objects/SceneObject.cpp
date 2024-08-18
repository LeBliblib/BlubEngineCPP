#include "SceneObject.h"

#include <iostream>
#include <ranges>

#include "../Components/DefaultComponent.h"
#include "../SceneManagement/Scene.h"
#include "../Components/Camera.h"
#include "../Components/TextureRenderer.h"

SceneObject::~SceneObject()
{
    std::cout << "SceneObject destroyed" << '\n';
}

Component* SceneObject::AddComponent(const BUILT_IN_TYPES type)
{
    Component* component = nullptr;
    
    switch (type) {
        case BUILT_IN_TYPES::NONE:
            component = AddComponent<DefaultComponent>();
            break;
        case BUILT_IN_TYPES::CAMERA:
            component = AddComponent<Camera>();
            break;
        case BUILT_IN_TYPES::TEXTURE_RENDERER:
            component = AddComponent<TextureRenderer>();
            break;
        case BUILT_IN_TYPES::TRANSFORM:
            component = transform.get();
            break;
    }

    return component;
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
