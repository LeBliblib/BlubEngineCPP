#include "Texture.h"

#include <algorithm>
#include <iostream>

Texture::~Texture() {
    std::cout << "Destroying texture at path: " << path << '\n';
    SDL_DestroyTexture(texture);
}

Texture::Texture(SDL_Texture *texture, std::string path) : texture(texture), path(std::move(path)) { }

SDL_Texture *Texture::getSDLTexture() const {
    return texture;
}

std::string_view Texture::getPath() const {
    return std::string_view(path);
}