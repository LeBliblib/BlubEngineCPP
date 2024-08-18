#pragma once
#include "Scene.h"

class SceneManager
{

public:
    [[nodiscard]] static Scene* GetActiveScene() { return activeScene.get(); }

    static void LoadNewScene();
    
private:
    static std::unique_ptr<Scene> activeScene;
};
