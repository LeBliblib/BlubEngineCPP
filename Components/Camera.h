#pragma once
#include "Component.h"

class Camera final : public Component
{
public:
   Camera() = delete;
   explicit Camera(SceneObject* obj) : Component(obj) {}
   
   [[nodiscard]] int GetPriority() const { return priority; }
   void SetPriority(int newPriority);

   static Camera* mainCamera;

   static void HandleCameraPriorityChange(Camera* camera);
   
   void OnAttached_Internal() override;
   void OnInitialized_Internal() override;
   void OnUpdate_Internal() override;
   void OnDestroyed_Internal() override;

private:
   int priority{};
   
};
