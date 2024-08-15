#pragma once
#include <unordered_map>

#include "../Objects/EngineObject.h"
#include "../Objects/SceneObject.h"

class Scene final : EngineObject
{
public:
    ~Scene() override;

    [[nodiscard]] SceneObject* CreateSceneObject() {
        auto sceneObject = std::make_unique<SceneObject>(this);
        SceneObject* rawSceneObject = sceneObject.get();

        sceneObjects[rawSceneObject->GetInstanceId()] = std::move(sceneObject);

        return rawSceneObject;
    }

    int UnregisterSceneObject(const int id) {
        if (!sceneObjects.contains(id)) {
            return 0;
        }

        sceneObjects.erase(id);
        return 1;
    }

    void Destroy() override;

private:
    std::unordered_map<int, std::unique_ptr<SceneObject>> sceneObjects{};
};
