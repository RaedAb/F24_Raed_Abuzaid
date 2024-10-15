//
//  TomatoWindow.h
//  Tomato
//
//  Created by Game on 9/26/24.
//

#ifndef TomatoWindow_h
#define TomatoWindow_h

#include "pch.h"
#include "WindowImpl.h"
#include "TomatoUtilities.h"

namespace Tmt
{
    class TOMATO_API TomatoWindow
    {
    public:
        static void Init();
        static std::unique_ptr<TomatoWindow>& GetWindow();
        
        void CreateWindow(int width, int height, std::string windowName);
        int GetWidth() const;
        int GetHeight() const;
        
        void SwapBuffers();
        void PollEvents();
        
    private:
        std::unique_ptr<WindowImpl> implementation{nullptr};
        
        TomatoWindow();
        
        inline static std::unique_ptr<TomatoWindow> instance;
    };
}


#endif /* TomatoWindow_h */
