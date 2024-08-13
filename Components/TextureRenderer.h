#pragma once

#include "../Rendering/Texture.h"
#include "Component.h"
#include "Transform.h"

class TextureRenderer : Component {
public:
    TextureRenderer() = default;
    explicit TextureRenderer(Transform* transform, Texture* texture, int sortingLayer);
    ~TextureRenderer();
    
    int sortingLayer{};
    Texture* texture{};

    [[nodiscard]] Vector2 getPosition() const;
    [[nodiscard]] double getRotation() const;
    [[nodiscard]] Vector2 getScale() const;

private:
    Transform* transform{};
};
