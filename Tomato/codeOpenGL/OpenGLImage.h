//
//  OpenGLImage.hpp
//  Tomato
//
//  Created by Game on 11/11/24.
//

#ifndef OpenGLImage_h
#define OpenGLImage_h

#include "../ImageImpl.h"
#include "../pch.h"

namespace Tmt
{
    class OpenGLImage : public ImageImpl
    {
    public:
        OpenGLImage();
        OpenGLImage(const std::string& filePath);
        
        
        virtual void LoadImage(const std::string& filePath) override;
        
        virtual bool HasImage() const override;
        virtual int GetHeight() const override;
        virtual int GetWidth() const override;
        
        virtual void Bind() override;
        
        std::unique_ptr<ImageImpl> Clone() const override {
            return std::make_unique<OpenGLImage>(*this);
        }
        
        ~OpenGLImage();
        
    private:
        unsigned int mImage{ 0 };
        int mHeight{ 0 };
        int mWidth{ 0 };
    };
}

#endif /* OpenGLImage_hpp */
