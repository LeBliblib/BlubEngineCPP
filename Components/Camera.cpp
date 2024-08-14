#include "Camera.h"

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
void Camera::OnUpdate_Internal() {}
void Camera::OnDestroyed_Internal() {}
