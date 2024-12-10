#include "pch.h"

#include "TomatoApplication.h"
#include "TomatoWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stbi_image.h"

namespace Tmt
{
    void TomatoApplication::Run()
    {
        Tmt::TomatoWindow::Init();
        Tmt::TomatoWindow::GetWindow()->CreateWindow(800, 600, "test");
        
        Renderer::Init();
        
        Initialize();
       
        // Shaders
        Tmt::Shaders shaders{
            "/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Shaders/defaultVertexShader.glsl",
            "/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Shaders/defaultFragmentShader.glsl"};
        
        shaders.SetIntUniform("ScreenDim", { 800, 600 });
        
        // Texture section
        Tmt::Image pic("/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Images/Drawing.png");
        
        // Main render loop
        while (ShouldContinue)
        {
            Update();
            
            Renderer::ClearScreen();
            
            Renderer::Draw(pic, 100, 100);
            
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
}

/*
 
Tmt::Image pic{"Assets/image"};
Tmt::Shader shader{"vert.glsl", "frag.glsl"};
Tmt::Renderer::Get()->Draw(pic, 100, 200, shader);
 
 */

