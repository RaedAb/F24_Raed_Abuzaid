//
//  WindowImpl.h
//  Tomato
//
//  Created by Game on 10/7/24.
//

#ifndef WindowImpl_h
#define WindowImpl_h

#include "pch.h"
#include "TomatoEvents.h"

namespace Tmt
{
    class WindowImpl
    {
    public:
        virtual void Create(int width, int height, std::string windowName) = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
        
        virtual void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) = 0;
        virtual void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler) = 0;
        
        virtual void SwapBuffers() = 0;
        virtual void PollEvents() = 0;
        
        virtual ~WindowImpl() {};
    };
}


#endif /* WindowImpl_h */
