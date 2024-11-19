#include "pch.h"

#include "TomatoApplication.h"
#include "TomatoWindow.h"
#include "Image.h"
#include "Shaders.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stbi_image.h"

namespace Tmt
{
    void TomatoApplication::Run()
    {
        Tmt::TomatoWindow::Init();
        Tmt::TomatoWindow::GetWindow()->CreateWindow(800, 600, "test");
        
        // Initialize glad after creating the context
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            TOMATO_ERROR("Failed to initialize GLAD");
        }
        
        Initialize();
        
        /** TESTING AREA **/
        float vertices[] = {
            100.0f, 100.0f, 0.0f, 0.0f, // left
            100.0f, 300.0f, 0.0f, 1.0f, // right
            300.0f, 300.0f, 1.0f, 1.0f, // top
            300.0f, 100.0f, 1.0f, 0.0f  // bottom-right
        };

        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        
        // Generate and bind Vertex Array Object (VAO)
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        // Shaders
        Tmt::Shaders shaders{
            "/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Shaders/defaultVertexShader.glsl",
            "/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Shaders/defaultFragmentShader.glsl"};
        
        shaders.SetIntUniform("ScreenDim", { 800, 600 });
        
        // Texture section
        Tmt::Image pic("/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Images/Drawing.png");
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        /** END OF TESTING AREA **/
        
        // Main render loop
        while (ShouldContinue)
        {
            Update();
            
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            shaders.Bind();
            glBindVertexArray(VAO);
            pic.Bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            
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

