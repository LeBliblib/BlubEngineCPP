#pragma once
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
    }
    ~SceneObject() override;
    
    [[nodiscard]] Transform* GetTransform() const { return transform.get(); }

    template<typename T>
    T* AddComponent() {
        static_assert(std::is_base_of_v<Component, T>, "T must be a Component type");

        auto component = std::make_unique<T>(this);
        T* rawComponent = component.get();

        components[rawComponent->GetInstanceId()] = std::move(component);

        rawComponent->OnAttached();
        return rawComponent;
    }

    int RemoveComponent(int id) {
        if (!components.contains(id)) {
            return 0;
        }

        components[id]->OnDestroyed();
        components.erase(id);
        return 1;
    }

    void Destroy() override;

private:
    Scene* scene{};
    
    std::unique_ptr<Transform> transform;

    std::unordered_map<int, std::unique_ptr<Component>> components{};
};
