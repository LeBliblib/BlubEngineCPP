#include "Marshal.h"

#include <iostream>

Transform* Marshal::UnmarshalTransform(intptr_t transformPtr)
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

SceneObject* Marshal::UnmarshalSceneObject(intptr_t sceneObjectPtr)
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
