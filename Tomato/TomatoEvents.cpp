//
//  TomatoEvents.cpp
//  Tomato
//
//  Created by Game on 12/11/24.
//

#include "pch.h"
#include "TomatoEvents.h"

namespace Tmt
{
    KeyEvent::KeyEvent(int keyCode, KeyAction action) : mKeyCode(keyCode), mAction(action)
    {
    }
    
    int KeyEvent::GetKeyCode() const
    {
        return mKeyCode;
    }
    
    KeyEvent::KeyAction KeyEvent::GetKeyAction() const
    {
        return mAction;
    }
    
    WindowEvent::WindowEvent(WindowAction action) : mAction(action)
    {
    }
    
    WindowEvent::WindowAction WindowEvent::GetWindowAction() const
    {
        return mAction;
    }
}


