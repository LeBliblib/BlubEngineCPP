#pragma once
#include "Scene.h"

class SceneManager
{

public:
    [[nodiscard]] static Scene* GetActiveScene() { return activeScene.get(); }

    static intptr_t LoadNewScene(int* instanceID);
    
private:
    static std::unique_ptr<Scene> activeScene;
};
