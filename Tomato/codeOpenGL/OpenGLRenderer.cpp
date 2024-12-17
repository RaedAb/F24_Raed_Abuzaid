//
//  OpenGLRenderer.cpp
//  Tomato
//
//  Created by Game on 11/21/24.
//
#include "pch.h"

#include "OpenGLRenderer.h"
#include "TomatoWindow.h"

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Tmt
{
    OpenGLRenderer::OpenGLRenderer()
    {
        // start GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            TOMATO_ERROR("Failed to initialize GLAD");
        }
        
        mDefaultShaders.LoadShaders(
            "../Tomato/TomatoAssets/Shaders/defaultVertexShader.glsl",
            "../Tomato/TomatoAssets/Shaders/defaultFragmentShader.glsl"
        );
        
        glGenVertexArrays(1, &mVAO);
        glBindVertexArray(mVAO);
        
        glGenBuffers(1, &mVBO);
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);
        
        glGenBuffers(1, &mEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
        
        // transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    
    void OpenGLRenderer::Draw(Image& pic, float xCoord, float yCoord, float width, float height)
    {
        float vertices[] = {
            xCoord,                  yCoord,                   0.0f, 0.0f,
            xCoord,                  yCoord + height,          0.0f, 1.0f,
            xCoord + width,          yCoord + height,          1.0f, 1.0f,
            xCoord + width,          yCoord,                   1.0f, 0.0f
        };
        
        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        mDefaultShaders.Bind();
        mDefaultShaders.SetIntUniform("ScreenDim",
                                      { TomatoWindow::GetWindow()->GetWidth(), TomatoWindow::GetWindow()->GetHeight() });
        
        glBindVertexArray(mVAO);
        pic.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    
    void OpenGLRenderer::Draw(Image& pic, float xCoord, float yCoord, float width, float height, Shaders &shader)
    {
        float vertices[] = {
            xCoord,                  yCoord,                   0.0f, 0.0f,
            xCoord,                  yCoord + height,          0.0f, 1.0f,
            xCoord + width,          yCoord + height,          1.0f, 1.0f,
            xCoord + width,          yCoord,                   1.0f, 0.0f
        };
        
        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        shader.Bind();
        glBindVertexArray(mVAO);
        pic.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    
    void OpenGLRenderer::ClearScreen()
    {
        glClearColor(0.5f, 0.6f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


