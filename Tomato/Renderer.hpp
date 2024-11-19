//
//  Renderer.hpp
//  Tomato
//
//  Created by Game on 11/18/24.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "pch.h"
#include "TomatoUtilities.h"
#include "Image.h"
#include "Shaders.h"

namespace Tmt
{
    class TOMATO_API Renderer
    {
    public:
        static void Init();
        
        static void Draw(Image& pic, int xCoord, int yCoord);
        static void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders);
        
    private:
        Renderer();
//        std::unique_ptr<RendererImpl> mImplementation;
        inline static std::unique_ptr<Renderer> mInstance;
    };
}

#endif /* Renderer_hpp */
