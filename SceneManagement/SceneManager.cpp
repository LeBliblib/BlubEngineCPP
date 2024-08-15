#include "SceneManager.h"
void SceneManager::LoadScene(std::string name)
{
    activeScene = std::make_unique<Scene>();
}
