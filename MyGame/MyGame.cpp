//
//  MyGameApplication.cpp
//  MyGame
//
//  Created by Game on 9/12/24.
//

//#include "MyGameApplication.hpp"
#include "Tomato.h"
#include <filesystem>
#include <iostream>

class MyGameApplication : public Tmt::TomatoApplication
{
    virtual void Initialize() override
    {
        TOMATO_LOG("Starting...");
        
        SetKeyEventHandler([this](const Tmt::KeyEvent& event) {MyKeysHandler(event); });
        
        try {
            // Get current working directory
            std::filesystem::path cwd = std::filesystem::current_path();
            
            // Print current working directory
            std::cout << "Current Working Directory: " << cwd << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    
    virtual void Update() override
    {
        Tmt::Renderer::Draw(blob);
    }
    
private:
    Tmt::Unit blob{ "../MyGame/Assets/Drawing.png", 100, 100 };
    
    void MyKeysHandler(const Tmt::KeyEvent& event)
    {
        if (event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Press)
        {
            switch (event.GetKeyCode())
            {
                case TOMATO_KEY_LEFT:
                    blob.UpdateXCoord(-10);
                    break;

                case TOMATO_KEY_RIGHT:
                    blob.UpdateXCoord(10);
                    break;
            }
        }
    }
};

TOMATO_GAME_START(MyGameApplication)
