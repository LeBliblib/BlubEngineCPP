#include "TransformBindings.h"

#include <iostream>

#include "Marshal.h"
#include "../Components//Transform.h"

extern "C"
{
    __declspec(dllexport) void GetPosition(const intptr_t transformPtr, Vector2* position)
    {
        try
        {
            *position = Marshal::UnmarshalTransform(transformPtr)->position;
        }
        catch (const std::exception& e)
        {
            std::cerr << "An error occurred while getting the position of the transform. \n" << e.what() << '\n';
            *position = {0, 0};
        }
    }
}

void SetPosition(const intptr_t transformPtr, const Vector2* position)
{
    try
    {
        const auto transform = Marshal::UnmarshalTransform(transformPtr);
        transform->position = *position;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while setting the position of the transform. \n" << e.what() << '\n';
    }
}

float GetRotation(const intptr_t transformPtr)
{
    try
    {
        return Marshal::UnmarshalTransform(transformPtr)->rotation;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while getting the rotation of the transform. \n" << e.what() << '\n';
        return 0;
    }
}

void SetRotation(const intptr_t transformPtr, const float rotation)
{
    try
    {
        const auto transform = Marshal::UnmarshalTransform(transformPtr);
        transform->rotation = rotation;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while setting the position of the transform. \n" << e.what() << '\n';
    }
}

void GetScale(const intptr_t transformPtr, Vector2* scale)
{
    try
    {
        *scale = Marshal::UnmarshalTransform(transformPtr)->scale;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while getting the scale of the transform. \n" << e.what() << '\n';
        *scale = {0, 0};
    }
}

void SetScale(const intptr_t transformPtr, const Vector2* scale)
{
    try
    {
        const auto transform = Marshal::UnmarshalTransform(transformPtr);
        transform->scale = *scale;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while setting the scale of the transform. \n" << e.what() << '\n';
    }
}
