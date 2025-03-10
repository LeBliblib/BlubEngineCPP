#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>

#include "EngineObject.h"
#include "../Components/Component.h"

#include "../Components/Transform.h"

class Scene;

class SceneObject final : public EngineObject
{
public:
    SceneObject() = delete;

    explicit SceneObject(Scene* scene) : scene(scene)
    {
        transform = std::make_unique<Transform>(this);
        transform->OnAttached();
        std::cout << "Set transform for scene object " << transform->GetInstanceId() << '\n';  
    }
    ~SceneObject() override;
    
    [[nodiscard]] Transform* GetTransform() const { return transform.get(); }

    template<typename T>
    [[nodiscard]] T* AddComponent() {
        static_assert(std::is_base_of_v<Component, T>, "T must be a Component type");

        auto component = std::make_unique<T>(this);
        T* rawComponent = component.get();

        components[rawComponent->GetInstanceId()] = std::move(component);

        std::cout << "Added component of type: " << typeid(T).name() << '\n';
        rawComponent->OnAttached();
        return rawComponent;
    }

    [[nodiscard]] Component* AddComponent(BUILT_IN_TYPES type);

    int RemoveComponent(const int id) {
        if (!components.contains(id)) {
            return 0;
        }

        components[id]->Destroy();
        components.erase(id);
        return 1;
    }

    /// <summary>
    /// This will destroy the SceneObject with all its components. Without unregistering it from the scene.
    /// </summary>
    void SoftDestroy();

    /// <summary>
    /// This will call SoftDestroy then unregister the SceneObject from its scene.
    /// </summary>
    void Destroy() override;
    
private:
    Scene* scene{};
    
    std::unique_ptr<Transform> transform;

    std::unordered_map<int, std::unique_ptr<Component>> components{};
};
