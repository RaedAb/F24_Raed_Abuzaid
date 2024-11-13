//
//  OpenGLImage.cpp
//  Tomato
//
//  Created by Game on 11/11/24.
//

#include "OpenGLImage.hpp"
#include "glad/glad.h"
#include "stbi_image.h"
#include "TomatoUtilities.h"

namespace Tmt
{
    OpenGLImage::OpenGLImage()
    {

    }
    
    OpenGLImage::OpenGLImage(const std::string& filePath)
    {
        glGenTextures(1, &mImage);
        glBindTexture(GL_TEXTURE_2D, mImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        unsigned char * data{ nullptr };
        int width{0}, height{0}, nrChannels{0};
        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            TOMATO_ERROR("Failed to load texture");
        }
        stbi_image_free(data);
    }
    
    void OpenGLImage::LoadImage(const std::string& filePath)
    {
        if (mImage)
            glDeleteTextures(1, &mImage);
            
        glGenTextures(1, &mImage);
        glBindTexture(GL_TEXTURE_2D, mImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        unsigned char * data{ nullptr };
        int nrChannels{ 0 };
        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            TOMATO_ERROR("Failed to load texture");
        }
        stbi_image_free(data);
    }
    
    bool OpenGLImage::HasImage() const
    {
        return mImage ? true : false;
    }
    
    int OpenGLImage::GetHeight() const
    {
        return mHeight;
    }
    
    int OpenGLImage::GetWidth() const
    {
        return mWidth;
    }
    
    void OpenGLImage::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, mImage);
    }
}

