#include "AssetManager.h"
#include "SDL_image.h"
#include "../Core/Core.h"
#include <iostream>

Texture *AssetManager::LoadTexture(const std::string_view path) {

    auto pathPtr = path.data();

    if(loadedTextures.contains(pathPtr)) {
        return loadedTextures[pathPtr].get();
    }
    
    auto texture = IMG_LoadTexture(Core::renderer, pathPtr);
    if(texture == nullptr) {
        std::cout << "Failed to load texture at path: " << path << '\n';
        std::cout << "Should be relative to: " << SDL_GetBasePath() << '\n';
        return nullptr;
    }

    auto uniqueTexturePtr = std::make_unique<Texture>(texture, pathPtr);

    loadedTextures[pathPtr] = std::move(uniqueTexturePtr);
    return loadedTextures[pathPtr].get();
}

std::unordered_map<std::string, std::unique_ptr<Texture>> AssetManager::loadedTextures{};

void AssetManager::Init() {
    loadedTextures.clear();
}