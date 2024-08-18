#include "TextureRendererBindings.h"

#include <iostream>

#include "../AssetsManagement/AssetManager.h"
#include "../Components/TextureRenderer.h"

extern "C" __declspec(dllexport) bool SetTexture(const intptr_t rendererPtr, char* pathPtr)
{
    TextureRenderer* renderer;
    const std::string path(pathPtr);
    
    std::cout << "Setting texture" << path << '\n';
    try
    {
        renderer = reinterpret_cast<TextureRenderer*>(rendererPtr);  // NOLINT(performance-no-int-to-ptr)

        if(renderer == nullptr)
        {
            std::cerr << "Renderer is null" << '\n';
            return false;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred while setting texture. \n" << e.what() << '\n';
        return false;
    }
    
    const auto texture = AssetManager::LoadTexture(path);
    if (texture == nullptr)
        return false;

    renderer->SetTexture(texture);
    return true;
}
