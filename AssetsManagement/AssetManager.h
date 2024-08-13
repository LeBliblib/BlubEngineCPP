#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "../Rendering/Texture.h"

class AssetManager {
public:
    static void init();
    static Texture* loadTexture(std::string_view path);

private:
    static std::unordered_map<std::string, std::unique_ptr<Texture>> loadedTextures;
};