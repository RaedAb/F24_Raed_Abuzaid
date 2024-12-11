#include "pch.h"

#include "TomatoApplication.h"
#include "TomatoWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stbi_image.h"

#include "KeyCodes.h"

namespace Tmt
{
    TomatoApplication::TomatoApplication()
    {
        Tmt::TomatoWindow::Init();
        Tmt::TomatoWindow::GetWindow()->CreateWindow(800, 600, "test");
        
        Renderer::Init();
        
        SetWindowEventHandler([this](const WindowEvent& event) { DefaultWindowEventHandler(event);
        });
    }
    
    void TomatoApplication::Run()
    {
        Initialize();
        
        Tmt::Image pic("/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Images/Drawing.png");
        
        // Main render loop
        int x = 100;
        int y = 100;
        
        SetKeyEventHandler([this, &x, &y](const KeyEvent& event) {
            if (event.GetKeyAction() == KeyEvent::KeyAction::Release)
                return;
            
            switch (event.GetKeyCode())
            {
                case TOMATO_KEY_UP:
                    y += 5;
                    break;
                case TOMATO_KEY_DOWN:
                    y -= 5;
                    break;
                case TOMATO_KEY_LEFT:
                    x -= 5;
                    break;
                case TOMATO_KEY_RIGHT:
                    x += 5;
                    break;
            }
            
        });
        
        mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
        
        while (mShouldContinue)
        {
            Update();
            
            Renderer::ClearScreen();
            
            Renderer::Draw(pic, x, y);
            
            std::this_thread::sleep_until(mNextFrameTime);
            mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
            
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
    
    
    void TomatoApplication::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
    {
        Tmt::TomatoWindow::GetWindow()->SetKeyEventHandler(newHandler);
    }
    
    void TomatoApplication::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
    {
        Tmt::TomatoWindow::GetWindow()->SetWindowEventHandler(newHandler);
    }
    
    void TomatoApplication::DefaultWindowEventHandler(const WindowEvent& event)
    {
        if (event.GetWindowAction() == WindowEvent::WindowAction::Close)
            mShouldContinue = false;
    }
    
    void TomatoApplication::DefaultKeyEventHandler(const KeyEvent& event)
    {
        // Not gonna use at the moment
    }
}
