#pragma once
#include "Scene.h"

class SceneManager
{

public:
    [[nodiscard]] Scene* GetActiveScene() const { return activeScene.get(); }

    void LoadScene(std::string name);
    
private:
    std::unique_ptr<Scene> activeScene;
};
