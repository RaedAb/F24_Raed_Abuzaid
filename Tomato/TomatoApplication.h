//
//  TomatoApplication.h
//  Tomato
//
//  Created by Game on 9/11/24.
//

#ifndef TomatoApplication_h
#define TomatoApplication_h

#include "TomatoUtilities.h"
#include "pch.h"

#include "TomatoEvents.h"

constexpr int FPS_RATE{ 60 };

namespace Tmt
{
    class TOMATO_API TomatoApplication
    {
    public:
        TomatoApplication();
        
        void Run();
        virtual void Initialize();
        virtual void Update();
        virtual void Shutdown();
        
        void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
        void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler);
        
        void DefaultWindowEventHandler(const WindowEvent& event);
        
    private:
        bool mShouldContinue{true};
        
        std::chrono::steady_clock::time_point mNextFrameTime;
        std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{ 1000 } / FPS_RATE };
    };
}

#endif /* TomatoApplication_h */
