#pragma once
#include "Component.h"
#include "../Maths/Vector2.h"
#include "../Maths/Vector2Int.h"

class Camera final : public Component
{
public:
   Camera() = delete;
   explicit Camera(SceneObject* obj) : Component(obj) {}
   
   [[nodiscard]] int GetPriority() const { return priority; }
   void SetPriority(int newPriority);

   float orthographicSize{5.0f};
   
   void OnAttached_Internal() override;
   void OnInitialized_Internal() override;
   void OnUpdate_Internal() override;
   void OnDestroyed_Internal() override;

   [[nodiscard]] Vector2Int GetWorldToScreenPoint(const Vector2& worldPoint) const;
   
   static Camera* mainCamera;

   static void HandleCameraPriorityChange(Camera* camera);

private:
   int priority{};
   
};
