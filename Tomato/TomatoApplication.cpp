//
//  TomatoApplication.cpp
//  Tomato
//
//  Created by Game on 9/11/24.
//
#include "pch.h"
#include "TomatoApplication.h"
#include <iostream>

namespace Tmt
{
    void TomatoApplication::Run()
    {
        Initialize();
        
        while (ShouldContinue)
        {
            Update();
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

