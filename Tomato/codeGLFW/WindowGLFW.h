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

namespace Tmt {
    class WindowGLFW : public WindowImpl
    {
    public:
        WindowGLFW();
        
        virtual void Create(int width, int height, std::string windowName) override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        
        virtual void SwapBuffers() override;
        virtual void PollEvents() override;
    
    private:
        GLFWwindow* mWindowPtr;
    };
}


#endif /* WindowGLFW_h */
