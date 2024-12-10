//
//  Renderer.cpp
//  Tomato
//
//  Created by Game on 11/18/24.
//

#include "pch.h"
#include "Renderer.h"
#include "RendererImpl.h"
#include "codeOpenGL/OpenGLRenderer.h"

namespace Tmt
{
    Renderer::Renderer()
    {
#ifdef TOMATO_OPENGL_STBI
        mImplementation = std::unique_ptr<RendererImpl>{ new OpenGLRenderer() };
#else
    #only_opengl_is_supported_so_far
#endif
    }
    
    void Renderer::Init()
    {
        if (mInstance == nullptr)
            mInstance = std::unique_ptr<Renderer>(new Renderer);
    }
    
    void Renderer::Draw(Image& pic, float xCoord, float yCoord)
    {
        mInstance->mImplementation->Draw(pic, xCoord, yCoord);
    }
    
    void Renderer::Draw(Image& pic, float xCoord, float yCoord, Shaders& shaders)
    {
        mInstance->mImplementation->Draw(pic, xCoord, yCoord, shaders);
    }
    
    void Renderer::ClearScreen()
    {
        mInstance->mImplementation->ClearScreen();
    }
}
