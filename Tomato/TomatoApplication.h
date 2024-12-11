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

constexpr int FPS_RATE{ 60 };

namespace Tmt
{
    class TOMATO_API TomatoApplication
    {
    public:
        void Run();
        virtual void Initialize();
        virtual void Update();
        virtual void Shutdown();
        
    private:
        bool ShouldContinue{true};
        
        std::chrono::steady_clock::time_point mNextFrameTime;
        std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{ 1000 } / FPS_RATE };
    };
}

#endif /* TomatoApplication_h */
