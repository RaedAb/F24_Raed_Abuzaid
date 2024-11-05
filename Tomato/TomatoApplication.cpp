#include "pch.h"
#include "TomatoApplication.h"
#include "TomatoWindow.h"
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
            std::cerr << "Failed to initialize GLAD" << std::endl;
            return;
        }
        
        Initialize();
        
        /** TESTING AREA **/
        // Define vertices for a simple triangle
        float vertices[] = {
            // positions     // texture coordinates
            -0.5f, -0.5f, 0.0f, 0.0f,  // Bottom-left
            0.5f, -0.5f, 1.0f, 0.0f,   // Bottom-right
            0.0f,  0.5f, 0.5f, 1.0f    // Top-center
        };

        
        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        
        // Generate and bind Vertex Array Object (VAO)
        // Generate and bind Vertex Array Object (VAO)
        unsigned int VAO, VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        
        glBindVertexArray(VAO);
        
        // Bind and set the vertex buffer data
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        // Bind and set the element buffer data
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        // Define position attribute (location = 0)
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);  // Position attribute
        
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);  // Texture coordinate attribute
        
        // Unbind VAO for now to prevent accidental modification
        glBindVertexArray(0);

        
        // Vertex Shader
        const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "layout(location = 1) in vec2 aTexCoord;\n"
        "out vec2 TexCoord;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
        "   TexCoord = aTexCoord;\n"
        "}\0";
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
        const char *fragmentShaderSource = "#version 330 core\n"
        "in vec2 TexCoord;\n"
        "out vec4 FragColor;\n"
        "uniform sampler2D ourTexture;\n"
        "void main()\n"
        "{\n"
        "   FragColor = texture(ourTexture, TexCoord);\n"
        "}\0";
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
        
        // Texture
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        int width{0}, height{0}, nrChannels{0};
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load("/Users/game/Desktop/Raed_Abuzaid_Fall_24/Tomato/TomatoAssets/Drawing.png", &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            TOMATO_ERROR("Failed to load texture");
        }
        stbi_image_free(data);
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        /** END OF TESTING AREA **/
        
        // Main render loop
        // Main render loop
        while (ShouldContinue)
        {
            Update(); // Your update function or input handling here
            
            // Clear the screen
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            // Use the shader program
            glUseProgram(shaderProgram);
            
            // Bind textures to corresponding texture units
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture);
            
            // Set the texture uniform locations
            glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0); // Texture unit 0
            glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1); // Texture unit 1
            
            // Bind VAO to draw the object
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // Draw using indices
            glBindVertexArray(0); // Optional: Unbind VAO
            
            Tmt::TomatoWindow::GetWindow()->SwapBuffers();
            Tmt::TomatoWindow::GetWindow()->PollEvents();
        }
        
        // Clean up resources
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
        
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

