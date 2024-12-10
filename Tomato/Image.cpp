//
//  Image.cpp
//  Tomato
//
//  Created by Game on 11/7/24.
//

#include "pch.h"
#include "Image.h"
#include "codeOpenGL/OpenGLImage.h"

namespace Tmt {
    Image::Image()
    {
#ifdef TOMATO_OPENGL_STBI
        implementation = std::unique_ptr<ImageImpl>{ new OpenGLImage() };
#else
    #only_opengl_is_supported_so_far
#endif
    }
    
    Image::Image(const std::string& filePath)
    {
#ifdef TOMATO_OPENGL_STBI
        implementation = std::unique_ptr<ImageImpl>{ new OpenGLImage(filePath) };
#else
    #only_opengl_is_supported_so_far
#endif
    }
    
    void Image::LoadImage(const std::string& filePath)
    {
        return implementation->LoadImage(filePath);
    }
    
    bool Image::HasImage() const
    {
        return implementation->HasImage();
    }
    
    int Image::GetHeight() const
    {
        return implementation->GetHeight();
    }
    
    int Image::GetWidth() const
    {
        return implementation->GetWidth();
    }
    
    void Image::Bind()
    {
        return implementation->Bind();
    }
}
