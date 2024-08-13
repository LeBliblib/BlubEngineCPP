#include <algorithm>
#include "RenderLoop.h"

#include <ranges>

#include "../Core/Core.h"

void RenderLoop::Register(TextureRenderer *textureRenderer) {
    textureRenderers[textureRenderer->sortingLayer].insert(textureRenderer);
}

void RenderLoop::Unregister(TextureRenderer *textureRenderer) {
    if (textureRenderers.contains(textureRenderer->sortingLayer)) {
        textureRenderers[textureRenderer->sortingLayer].erase(textureRenderer);
    }
}

void RenderLoop::Render() { 
    for (auto& renderers : textureRenderers | std::views::values) {
        for (auto& renderer : renderers) {
            SDL_Rect destRect = {150, 150, 25, 25};
            SDL_RenderCopyEx(Core::renderer, renderer->texture->getSDLTexture(), nullptr,
                             &destRect, renderer->getRotation(), nullptr, SDL_FLIP_NONE);
        }
    }
}

std::map<int, std::unordered_set<TextureRenderer*>> RenderLoop::textureRenderers{};

void RenderLoop::Init() {
    textureRenderers.clear();
}
