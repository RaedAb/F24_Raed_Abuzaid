//
//  Shaders.cpp
//  Tomato
//
//  Created by Game on 11/14/24.
//

#include "pch.h"
#include "Shaders.h"
#include "codeOpenGL/OpenGLShaders.hpp"

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
    
    std::string ReadFile(const std::string& fileName)
    {
        std::ifstream input{ fileName };
        
        assert(input);
        
        std::string result;
        std::string line;
        
        while(input)
        {
            getline(input, line);
            result += line;
            result += "/n";
        }
        
        input.close();
        
        return result;
    }
}

