//
//  TomatoApplication.cpp
//  Tomato
//
//  Created by Game on 9/11/24.
//
#include "pch.h"

#include "TomatoApplication.h"
#include "TomatoWindow.h"
#include <glad/glad.h>
#include <stbi_image.h>

namespace Tmt
{
    void TomatoApplication::Run()
    {
        Tmt::TomatoWindow::Init();
        Tmt::TomatoWindow::GetWindow()->CreateWindow(800, 600, "test");
        
        Initialize();
        
        while (ShouldContinue)
        {
            
            Update();
            
            Tmt::TomatoWindow::GetWindow()->SwapBuffers();
            Tmt::TomatoWindow::GetWindow()->PollEvents();
        }
        
        Shutdown();
    }
    
    void TomatoApplication::Initialize()
    {
    }
    
    void TomatoApplication::Update()
    {
    }
    
    void TomatoApplication::Shutdown()
    {
    }
}

