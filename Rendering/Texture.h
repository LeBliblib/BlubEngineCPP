#pragma once

#include <SDL.h>
#include <string>

#include "../Maths/Vector2Int.h"
#include "../Objects/EngineObject.h"

class Texture : EngineObject {

public:
    Texture() = default;
    explicit Texture(SDL_Texture* texture, std::string path);
    ~Texture() override;

    // Textures can't be copied, there should be only one instance of each texture file, loaded in AssetManager
    
    // Copy constructor
    Texture(const Texture& other) = delete;
    // Move constructor
    Texture(Texture&& other) = delete;
    // Copy assignment operator
    Texture& operator=(const Texture& other) = delete;
    // Move assignment operator
    Texture& operator=(Texture&& other) = delete;

    [[nodiscard]] SDL_Texture* GetSdlTexture() const;
    [[nodiscard]] std::string_view GetPath() const;

    [[nodiscard]] Vector2Int GetSize() const;

private:
    SDL_Texture* texture{};
    std::string path;

    Vector2Int cachedSize;
    [[nodiscard]] Vector2Int GetSdlTextureSize() const;

public:
    void Destroy() override;
};

