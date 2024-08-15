#include "Texture.h"

#include <algorithm>
#include <iostream>

Texture::~Texture() {
    std::cout << "Destroying texture at path: " << path << '\n';
    SDL_DestroyTexture(texture);
}

Texture::Texture(SDL_Texture *texture, std::string path) : texture(texture), path(std::move(path))
{
    cachedSize = GetSdlTextureSize();
}

SDL_Texture *Texture::GetSdlTexture() const {
    return texture;
}

std::string_view Texture::GetPath() const {
    return std::string_view(path);
}

Vector2Int Texture::GetSize() const
{
    return cachedSize;
}

Vector2Int Texture::GetSdlTextureSize() const
{
    Vector2Int size;
    
    if(SDL_QueryTexture(texture, nullptr, nullptr, &size.x, &size.y) != 0)
    {
        std::cout << "Failed to get texture size: " << SDL_GetError() << '\n';
        return {};
    }
    
    return size;
}

void Texture::Destroy() {}
