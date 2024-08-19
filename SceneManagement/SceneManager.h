#pragma once
#include "Scene.h"

class SceneManager
{
private:
    typedef void (*SceneLoadDelegate)(intptr_t scenePtr, int sceneId);
    static SceneLoadDelegate sceneLoadRequest;
    static bool sceneLoadRequested;
    
public:
    [[nodiscard]] static Scene* GetActiveScene() { return activeScene.get(); }

    static void RequestSceneLoad(const intptr_t requestPtr);
    static void LoadNewScene();

    static intptr_t ForceSceneLoad(int* instanceId);

    static void OnFrameStart();
    
private:
    static std::unique_ptr<Scene> activeScene;
};
