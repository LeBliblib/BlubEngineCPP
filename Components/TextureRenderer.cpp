#include "TextureRenderer.h"

#include <iostream>

#include "../Rendering/RenderLoop.h"

TextureRenderer::~TextureRenderer()
{
    std::cout << "TextureRenderer destroyed" << '\n';
}

void TextureRenderer::OnAttached_Internal()
{
    RenderLoop::Register(this);
}

void TextureRenderer::OnInitialized_Internal() {}

void TextureRenderer::OnUpdate_Internal()
{
}

void TextureRenderer::OnDestroyed_Internal()
{
    RenderLoop::Unregister(this);
}
