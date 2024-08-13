#include "TextureRenderer.h"

#include <iostream>

TextureRenderer::TextureRenderer(Transform* transform, Texture *texture, int sortingLayer) {
    this->transform = transform;
    this->texture = texture;
    this->sortingLayer = sortingLayer;
}

TextureRenderer::~TextureRenderer()
{
    std::cout << "Destroying TextureRenderer\n";
}

Vector2 TextureRenderer::getPosition() const {
    return transform->position;
}

double TextureRenderer::getRotation() const {
    return 0;
    //return transform->rotation;
}

Vector2 TextureRenderer::getScale() const {
    return transform->scale;
}