//
//  WindowGLFW.h
//  Tomato
//
//  Created by Game on 10/7/24.
//

#ifndef WindowGLFW_h
#define WindowGLFW_h

#include "../WindowImpl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "pch.h"
#include "TomatoEvents.h"

namespace Tmt {
    class WindowGLFW : public WindowImpl
    {
    public:
        WindowGLFW();
        
        virtual void Create(int width, int height, std::string windowName) override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        
        virtual void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) override;
        virtual void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler) override;
        
        virtual void SwapBuffers() override;
        virtual void PollEvents() override;
    
    private:
        GLFWwindow* mWindowPtr;
        
        struct CallBacks
        {
            std::function<void(const KeyEvent&)> KeyEventHandler{ [](const KeyEvent&) {} };
            std::function<void(const WindowEvent&)> WindowEventHandler{ [](const WindowEvent&) {} };
        } mCallBacks;
    };
}


#endif /* WindowGLFW_h */
