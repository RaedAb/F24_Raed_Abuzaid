//
//  TomatoEvents.h
//  Tomato
//
//  Created by Game on 12/11/24.
//

#ifndef TomatoEvents_h
#define TomatoEvents_h

#include "TomatoUtilities.h"

namespace Tmt
{
    class TOMATO_API KeyEvent
    {
    public:
        enum class KeyAction{Press, Release, Repeat};
        
        KeyEvent(int keyCode, KeyAction action = KeyAction::Press);
        
        int GetKeyCode() const;
        KeyAction GetKeyAction() const;
        
        
    private:
        int mKeyCode{ -1 };
        KeyAction mAction{ KeyAction::Press };
    };
    
    class TOMATO_API WindowEvent
    {
    public:
        enum class WindowAction{Close, Minimize, Maximize, Resize};

        WindowEvent(WindowAction action);
        
        WindowAction GetWindowAction() const;
        
    private:
        WindowAction mAction{ WindowAction::Resize };
        
    };
}

#endif /* TomatoEvents_h */
