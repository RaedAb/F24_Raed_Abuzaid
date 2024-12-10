//
//  Renderer.hpp
//  Tomato
//
//  Created by Game on 11/18/24.
//

#ifndef Renderer_h
#define Renderer_h

#include "pch.h"
#include "TomatoUtilities.h"
#include "Image.h"
#include "Shaders.h"
#include "RendererImpl.h"

namespace Tmt
{
    class TOMATO_API Renderer
    {
    public:
        static void Init();
        
        static void Draw(Image& pic, float xCoord, float yCoord);
        static void Draw(Image& pic, float xCoord, float yCoord, Shaders& shaders);
        
        static void ClearScreen();
        
    private:
        Renderer();
        
        std::unique_ptr<RendererImpl> mImplementation;
        inline static std::unique_ptr<Renderer> mInstance;
    };
}

#endif /* Renderer_hpp */
