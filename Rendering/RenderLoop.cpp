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

void GetDestRectForRenderer(const TextureRenderer* renderer, SDL_Rect* rect)
{
    auto transform = renderer->sceneObject->GetTransform();

    auto screenPos = Camera::mainCamera->GetWorldToScreenPoint(transform->position);

    auto objSize = Vector2{renderer->texture->GetSize()};
    objSize *= 0.01f;
    objSize *= transform->scale;
            
    int width;
    int height;
    SDL_GetWindowSize(Core::window, &width, &height);
            
    objSize = objSize * static_cast<float>(height) / Camera::mainCamera->orthographicSize;
            
    const auto screenSize = Vector2Int{objSize}; 
            
    *rect = {screenPos.x - screenSize.x / 2, screenPos.y - screenSize.y / 2, screenSize.x, screenSize.y};
}

void RenderLoop::Render() { 
    for (auto& renderers : textureRenderers | std::views::values) {
        for (auto& renderer : renderers) {

            if(renderer->texture == nullptr) {
                continue;
            }

            SDL_Rect destRect{};
            GetDestRectForRenderer(renderer, &destRect);

            SDL_RenderCopyEx(Core::renderer, renderer->texture->GetSdlTexture(), nullptr,
                             &destRect, renderer->sceneObject->GetTransform()->rotation, nullptr, SDL_FLIP_NONE);
        }
    }
}


std::map<int, std::unordered_set<TextureRenderer*>> RenderLoop::textureRenderers{};

void RenderLoop::Init() {
    textureRenderers.clear();
}
