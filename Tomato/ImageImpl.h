//
//  ImageImpl.h
//  Tomato
//
//  Created by Game on 11/11/24.
//

#ifndef ImageImpl_h
#define ImageImpl_h
#include "pch.h"

namespace Tmt
{
    class ImageImpl
    {
    public:
        virtual void LoadImage(const std::string& filePath) = 0;
        
        virtual bool HasImage() const = 0;
        virtual int GetHeight() const = 0;
        virtual int GetWidth() const = 0;
        
        virtual void Bind() = 0;
        
        virtual std::unique_ptr<ImageImpl> Clone() const = 0;
        
        virtual ~ImageImpl() {};
    };
}


#endif /* ImageImpl_h */
