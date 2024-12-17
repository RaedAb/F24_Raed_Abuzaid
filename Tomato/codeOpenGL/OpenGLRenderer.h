//
//  OpenGLRenderer.hpp
//  Tomato
//
//  Created by Game on 11/21/24.
//

#ifndef OpenGLRenderer_h
#define OpenGLRenderer_h

#include "../RendererImpl.h"

namespace Tmt
{
    class OpenGLRenderer : public RendererImpl
    {
    public:
        OpenGLRenderer();
        virtual void Draw(Image& pic, float xCoord, float yCoord, float width, float height) override;
        virtual void Draw(Image& pic, float xCoord, float yCoord, float width, float height, Shaders &shader) override;
        
        void ClearScreen() override;
        
    private:
        unsigned int mVBO{ 0 };
        unsigned int mVAO{ 0 };
        unsigned int mEBO{ 0 };
        
        Shaders mDefaultShaders;
    };
}

#endif /* OpenGLRenderer_hpp */
