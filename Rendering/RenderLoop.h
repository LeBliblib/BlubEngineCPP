#pragma once

#include <unordered_set>
#include <map>
#include "../Components/TextureRenderer.h"

class RenderLoop {

public:
    static void Init();

    static void Register(TextureRenderer* textureRenderer);
    static void Unregister(TextureRenderer* textureRenderer);

    static void Render();

private:
    static std::map<int, std::unordered_set<TextureRenderer*>> textureRenderers;
};

