//
//  Shaders.h
//  Tomato
//
//  Created by Game on 11/14/24.
//

#ifndef Shaders_h
#define Shaders_h

#include "TomatoUtilities.h"
#include "pch.h"
#include "ShadersImpl.h"

namespace Tmt
{
    class TOMATO_API Shaders
    {
    public:
        Shaders();
        Shaders(const std::string & vertexSFile, const std::string& fragmentSFile);
        void LoadShaders(const std::string & vertexSFile, const std::string& fragmentSFile);
        
        void Bind();
        void SetIntUniform(const std::string& uniformName, const std::vector<int>& values);
        
    private:
        std::unique_ptr<ShadersImpl> implementation;
        
        std::string ReadFile(const std::string& filePath);
    };
}


#endif /* Shaders_h */
