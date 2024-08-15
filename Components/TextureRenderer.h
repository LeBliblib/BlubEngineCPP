#pragma once

#include "../Rendering/Texture.h"
#include "Component.h"

class TextureRenderer final : public Component {
public:

    TextureRenderer() = delete;
    explicit TextureRenderer(SceneObject* obj) : Component(obj) {}
~TextureRenderer() override;
    
    void SetTexture(Texture* tex) {
        texture = tex;
    }

    void SetSortingLayer(int layer) {
        sortingLayer = layer;
    }

    void OnAttached_Internal() override;
    void OnInitialized_Internal() override;
    void OnUpdate_Internal() override;
    void OnDestroyed_Internal() override;

    int sortingLayer{};
    Texture* texture{};
};
