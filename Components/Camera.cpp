#include "Camera.h"

#include <iostream>
#include <SDL_video.h>

#include "../Core/Core.h"
#include "../InputsManagement/InputsManager.h"
#include "../Objects/SceneObject.h"
#include "../TimeManagement/Time.h"

Camera* Camera::mainCamera = nullptr;

void Camera::SetPriority(int newPriority)
{
    priority = newPriority;
    HandleCameraPriorityChange(this);
}

void Camera::HandleCameraPriorityChange(Camera* camera)
{
    if (mainCamera == nullptr || camera->GetPriority() > mainCamera->GetPriority())
    {
        mainCamera = camera;
    }
}

void Camera::OnAttached_Internal() {}
void Camera::OnInitialized_Internal() {}
void Camera::OnUpdate_Internal()
{
    if(InputsManager::IsKeyPressed(SDLK_d))
    {
        sceneObject->GetTransform()->position.x += 0.5f * Time::GetDeltaTime();
    }
}
void Camera::OnDestroyed_Internal() {}

Vector2Int Camera::GetWorldToScreenPoint(const Vector2& worldPoint) const
{
    const auto centerPosition = sceneObject->GetTransform()->position;
    
    int width;
    int height;
    SDL_GetWindowSize(Core::window, &width, &height);
    
    auto aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    
    const auto topLeftPosition = Vector2{centerPosition.x - (orthographicSize * 0.5f * aspectRatio), centerPosition.y + orthographicSize * 0.5f};
    
    auto relativeFloat = worldPoint - topLeftPosition;
    relativeFloat.x /= orthographicSize * aspectRatio;
    relativeFloat.y /= orthographicSize;
    
    relativeFloat.x *= width;
    relativeFloat.y *= height;
    
    Vector2Int relativePosition = Vector2Int{relativeFloat};

    relativePosition.y = -relativePosition.y;
    
    return relativePosition;
}
