//
//  Shaders.cpp
//  Tomato
//
//  Created by Game on 11/14/24.
//

#include "pch.h"
#include "Shaders.h"
#include "codeOpenGL/OpenGLShaders.h"

namespace Tmt
{
    Shaders::Shaders()
    {
#ifdef TOMATO_OPENGL_STBI
        implementation = std::unique_ptr<ShadersImpl>{ new OpenGLShaders() };
#else
    #only_opengl_is_supported_so_far
#endif
    }
    
    Shaders::Shaders(const std::string & vertexSFile, const std::string& fragmentSFile)
    {
#ifdef TOMATO_OPENGL_STBI
        implementation = std::unique_ptr<ShadersImpl>{ new OpenGLShaders(vertexSFile, fragmentSFile) };
#else
    #only_opengl_is_supported_so_far
#endif
    }
    
    void Shaders::LoadShaders(const std::string & vertexSFile, const std::string& fragmentSFile)
    {
        implementation->LoadShaders(vertexSFile, fragmentSFile);
    }
    
    void Shaders::Bind()
    {
        implementation->Bind();
    }
    
    void Shaders::SetIntUniform(const std::string& uniformName, const std::vector<int>& values)
    {
        implementation->SetIntUniform(uniformName, values);
    }
    
    void Shaders::SetIntUniform(const std::string& uniformName, int value)
    {
        implementation->SetIntUniform(uniformName, value);
    }
    
    std::string Shaders::ReadFile(const std::string& fileName)
    {
        return implementation->ReadFile(fileName);
    }
}

