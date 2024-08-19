#include "CameraBindings.h"

#include "Marshal.h"

void SetPriority(const intptr_t cameraPtr, const int priority)
{
    try
    {
        const auto camera = Marshal::UnmarshalCamera(cameraPtr);
        if(camera == nullptr)
        {
            std::cerr << "Unable to set camera priority. Camera couldn't be found. \n";
            return;
        }

        camera->SetPriority(priority);
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while setting the camera priority. \n" << e.what() << '\n';
    }
}

int GetPriority(const intptr_t cameraPtr)
{
    try
    {
        const auto camera = Marshal::UnmarshalCamera(cameraPtr);
        if(camera == nullptr)
        {
            std::cerr << "Unable to get camera priority. Camera couldn't be found. \n";
            return 0;
        }

        return camera->GetPriority();
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while getting the camera priority. \n" << e.what() << '\n';
        return 0;
    }
}

void SetOrthographicSize(const intptr_t cameraPtr, const float size)
{
    try
    {
        const auto camera = Marshal::UnmarshalCamera(cameraPtr);
        if(camera == nullptr)
        {
            std::cerr << "Unable to set camera size. Camera couldn't be found. \n";
            return;
        }

        camera->orthographicSize = size;
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while setting the camera size. \n" << e.what() << '\n';
    }
}

float GetOrthographicSize(const intptr_t cameraPtr)
{
    try
    {
        const auto camera = Marshal::UnmarshalCamera(cameraPtr);
        if(camera == nullptr)
        {
            std::cerr << "Unable to get camera size. Camera couldn't be found. \n";
            return 0;
        }

        return camera->orthographicSize;
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while getting the camera size. \n" << e.what() << '\n';
        return 0;
    }
}

void WorldToScreenPoint(const intptr_t cameraPtr, const Vector2 worldPoint, Vector2Int* screenPoint)
{
    try
    {
        const auto camera = Marshal::UnmarshalCamera(cameraPtr);
        if(camera == nullptr)
        {
            std::cerr << "Unable to perform camera WorldToScreenPoint. Camera couldn't be found. \n";
            *screenPoint = {};
            return;
        }

        *screenPoint = camera->GetWorldToScreenPoint(worldPoint);
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while getting the camera size. \n" << e.what() << '\n';
        *screenPoint = {};
    }
}
