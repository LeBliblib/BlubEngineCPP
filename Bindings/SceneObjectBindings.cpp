#include "SceneObjectBindings.h"

#include <exception>
#include <iostream>

#include "Marshal.h"
#include "../Objects/SceneObject.h"
#include "../Components/Component.h"

extern "C" __declspec(dllexport) bool DestroySceneObject(const intptr_t sceneObjectPtr)
{
    try
    {
        const auto sceneObject = Marshal::UnmarshalSceneObject(sceneObjectPtr);  // NOLINT(performance-no-int-to-ptr)

        sceneObject->Destroy();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while destroying the scene object. \n" << e.what() << '\n';
        return false;
    }
}

extern "C" __declspec(dllexport) bool AddComponent(const intptr_t sceneObjectPtr, int componentType, const intptr_t* eventMethodPtrs,
                  int* eventMethodsType, const int eventMethodCount, intptr_t* componentPtr, int* instanceId)
{
    try
    {
        const auto sceneObject = Marshal::UnmarshalSceneObject(sceneObjectPtr);
        const auto compType = static_cast<BUILT_IN_TYPES>(componentType);

        const auto component = sceneObject->AddComponent(compType);

        for(int i = 0; i < eventMethodCount; i++)
        {
            const auto type = static_cast<EVENT_METHOD_TYPE>(eventMethodsType[i]);
            
            if(type == EVENT_METHOD_TYPE::ATTACHED)
            {
                // c# scripting backend will call the Attached method.
                // We don't want to it here because it will be too soon (c# instance doesn't have IntPtr yet)
                // This should not happen, c# should not send EVENT_METHOD_TYPE::ATTACHED,
                // but if it does for some reason, we don't need to store it.
                continue;   
            }
            
            component->AddEventMethod(type, eventMethodPtrs[i]);
        }

        *instanceId = component->GetInstanceId();
        *componentPtr = component->GetIntPtr();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while adding component. \n" << e.what() << '\n';
        return false;
    }
}

extern "C" __declspec(dllexport) bool RemoveComponent(const intptr_t sceneObjectPtr, const int componentId)
{
    try
    {
        const auto sceneObject = Marshal::UnmarshalSceneObject(sceneObjectPtr);
        sceneObject->RemoveComponent(componentId);
        
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while removing component. \n" << e.what() << '\n';
        return false;
    }
}
