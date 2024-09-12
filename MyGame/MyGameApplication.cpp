//
//  MyGameApplication.cpp
//  MyGame
//
//  Created by Game on 9/12/24.
//

//#include "MyGameApplication.hpp"
#include "include/Tomato.h"
#include <iostream>

class MyGameApplication : public Tmt::TomatoApplication
{
    virtual void Initialize() override
    {
        std::cout << "Starting..." << std::endl;
    }
    
    virtual void Update() override
    {
//        std::cout << "Running..." << std::endl;
    }
};

TOMATO_GAME_START(MyGameApplication)
