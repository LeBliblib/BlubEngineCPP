#pragma once
#include <unordered_map>

#include "../Objects/EngineObject.h"
#include "../Objects/SceneObject.h"

class Scene final : EngineObject
{
public:
    ~Scene() override;

    [[nodiscard]] SceneObject* CreateSceneObject() {
        auto sceneObject = std::make_unique<SceneObject>();
        SceneObject* rawSceneObject = sceneObject.get();

        sceneObjects[rawSceneObject->instanceId] = std::move(sceneObject);

        return rawSceneObject;
    }

    int DestroySceneObject(const int id) {
        if (!sceneObjects.contains(id)) {
            return 0;
        }

        sceneObjects.erase(id);
        return 1;
    }
    
private:
    std::unordered_map<int, std::unique_ptr<SceneObject>> sceneObjects{};
};
