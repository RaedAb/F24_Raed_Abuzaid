#include "pch.h"

#include "TomatoApplication.h"
#include "TomatoWindow.h"
#include "Image.h"

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
            300.0f, 100.0f, 1.0f, 1.0f  // bottom-right
            
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
        
        // Vertex Shader
        const char *vertexShaderSource = R"(
        #version 330 core
        
        layout (location = 0) in vec2 aPos;
        layout(location = 1) in vec2 aTexCoord;
        
        out vec2 TexCoord;
        
        uniform ivec2 ScreenDim;
        
        void main()
        {
            gl_Position = vec4(2*aPos.x/ScreenDim.x - 1, 2*aPos.y/ScreenDim.y - 1, 0.0, 1.0);
            TexCoord = aTexCoord;
        }
        )";
        
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            TOMATO_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
        }
        
        // Fragment Shader
        const char *fragmentShaderSource = R"(
        #version 330 core
        
        in vec2 TexCoord;
        uniform sampler2D ourTexture;
        
        out vec4 FragColor;
        
        void main()
        {
            FragColor = texture(ourTexture, TexCoord);
        }
        )";
        
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            TOMATO_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
        }
        
        // Shader Program
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            TOMATO_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        
        glUseProgram(shaderProgram);
        int location(glGetUniformLocation(shaderProgram, "ScreenDim"));
        glUniform2i(location, 800, 600);
        
        // Texture section
        Tmt::Image pic("../Tomato/TomatoAssets/Drawing.png");
        
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        /** END OF TESTING AREA **/
        
        // Main render loop
        while (ShouldContinue)
        {
            Update();
            
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            glUseProgram(shaderProgram);
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

