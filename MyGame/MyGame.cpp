//
//  MyGameApplication.cpp
//  MyGame
//
//  Created by Game on 9/12/24.
//

//#include "MyGameApplication.hpp"
#include "Tomato.h"
#include <iostream>

class MyGameApplication : public Tmt::TomatoApplication
{
    virtual void Initialize() override
    {
        TOMATO_LOG("Starting...");
        TOMATO_ERROR("Error");
    }
    
    virtual void Update() override
    {
        
    }
};

TOMATO_GAME_START(MyGameApplication)
