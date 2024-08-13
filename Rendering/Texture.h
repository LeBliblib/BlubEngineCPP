#pragma once

#include <SDL.h>
#include <string>

class Texture {

public:
    Texture() = default;
    explicit Texture(SDL_Texture* texture, std::string path);
    ~Texture();

    [[nodiscard]] SDL_Texture* getSDLTexture() const;
    [[nodiscard]] std::string_view getPath() const;

private:
    SDL_Texture* texture{};
    std::string path;

};

