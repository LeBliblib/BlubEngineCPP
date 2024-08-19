#include "Marshal.h"

#include <iostream>

Transform* Marshal::UnmarshalTransform(const intptr_t transformPtr)
{
    try
    {
        return reinterpret_cast<Transform*>(transformPtr);  // NOLINT(performance-no-int-to-ptr)
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while unmarshalling the transform. \n" << e.what() << '\n';
        return nullptr;
    }
}

SceneObject* Marshal::UnmarshalSceneObject(const intptr_t sceneObjectPtr)
{
    try
    {
        return reinterpret_cast<SceneObject*>(sceneObjectPtr);  // NOLINT(performance-no-int-to-ptr)
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while unmarshalling the SceneObject. \n" << e.what() << '\n';
        return nullptr;
    }
}

Camera* Marshal::UnmarshalCamera(const intptr_t cameraPtr)
{
    try
    {
        return reinterpret_cast<Camera*>(cameraPtr);  // NOLINT(performance-no-int-to-ptr)
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while unmarshalling the SceneObject. \n" << e.what() << '\n';
        return nullptr;
    }
}
