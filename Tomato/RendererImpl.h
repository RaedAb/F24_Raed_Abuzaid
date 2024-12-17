//
//  RendererImpl.h
//  Tomato
//
//  Created by Game on 11/21/24.
//

#ifndef RendererImpl_h
#define RendererImpl_h

#include "Shaders.h"
#include "Image.h"

namespace Tmt
{
    class RendererImpl
    {
    public:
        virtual void Draw(Image& pic, float xCoord, float yCoord, float width, float height) = 0;
        virtual void Draw(Image& pic, float xCoord, float yCoord, float width, float height, Shaders &shader) = 0;
        
        virtual void ClearScreen() = 0;
        
        virtual ~RendererImpl() {};
        
    private:
        
    };
}

#endif /* RendererImpl_h */
