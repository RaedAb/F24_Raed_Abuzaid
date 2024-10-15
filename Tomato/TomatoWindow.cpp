//
//  TomatoWindow.cpp
//  Tomato
//
//  Created by Game on 9/30/24.
//

#include "pch.h"
#include "TomatoWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Tmt
{
    TomatoWindow::TomatoWindow()
    {
#ifdef TOMATO_GLFW
        implementation = std::unique_ptr<WindowImpl> { new WindowGLFW };
#else
        #window_implementation_isnt_chosen
#endif
    }
    
    void TomatoWindow::Init()
    {
        if (!instance)
            instance = std::unique_ptr<TomatoWindow>{ new TomatoWindow};
    }
    
    std::unique_ptr<TomatoWindow>& TomatoWindow::GetWindow()
    {
        return instance;
    }
    
    void TomatoWindow::CreateWindow(int width, int height, std::string windowName)
    {
        implementation->Create(width, height, windowName);
    }
    
    int TomatoWindow::GetWidth() const
    {
        return implementation->GetWidth();
    }
    
    int TomatoWindow::GetHeight() const
    {
        return implementation->GetHeight();
    }
    
    void TomatoWindow::SwapBuffers()
    {
        implementation->SwapBuffers();
    }
    
    void TomatoWindow::PollEvents()
    {
        implementation->PollEvents();
    }
}


