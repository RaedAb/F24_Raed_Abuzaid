//
//  WindowImpl.h
//  Tomato
//
//  Created by Game on 10/7/24.
//

#ifndef WindowImpl_h
#define WindowImpl_h

#include "pch.h"

namespace Tmt
{
    class WindowImpl
    {
    public:
        virtual void Create(int width, int height, std::string windowName) = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        virtual void SwapBuffers() = 0;
        virtual void PollEvents() = 0;
    };
}


#endif /* WindowImpl_h */
