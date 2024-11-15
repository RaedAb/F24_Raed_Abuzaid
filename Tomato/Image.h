//
//  Image.h
//  Tomato
//
//  Created by Game on 11/7/24.
//

#ifndef Image_h
#define Image_h
#include "TomatoUtilities.h"
#include "pch.h"
#include "ImageImpl.h"

namespace Tmt
{
    class TOMATO_API Image
    {
    public:
        Image();
        Image(const std::string& filePath);
        void LoadImage(const std::string& filePath);
        
        bool HasImage() const;
        int GetHeight() const;
        int GetWidth() const;
        
        void Bind();
        
    private:
        
        std::unique_ptr<ImageImpl> implementation;
        
        friend class Renderer;
        
        
    };
}


#endif /* Image_h */
