#include <algorithm>
#include "RenderLoop.h"

#include <ranges>

#include "../Components/Camera.h"
#include "../Core/Core.h"
#include "../Objects/SceneObject.h"

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

            if(renderer->texture == nullptr) {
                continue;
            }
            
            auto transform = renderer->sceneObject->GetTransform();

            auto screenPos = Camera::mainCamera->GetWorldToScreenPoint(transform->position);
            
            SDL_Rect destRect = {screenPos.x - 32, screenPos.y - 32, 64, 64};
            SDL_RenderCopyEx(Core::renderer, renderer->texture->getSDLTexture(), nullptr,
                             &destRect, transform->rotation, nullptr, SDL_FLIP_NONE);
        }
    }
}

std::map<int, std::unordered_set<TextureRenderer*>> RenderLoop::textureRenderers{};

void RenderLoop::Init() {
    textureRenderers.clear();
}
