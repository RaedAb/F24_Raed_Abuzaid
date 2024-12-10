//
//  OpenGLShaders.hpp
//  Tomato
//
//  Created by Game on 11/14/24.
//

#ifndef OpenGLShaders_h
#define OpenGLShaders_h

#include "../ShadersImpl.h"
#include "pch.h"

namespace Tmt
{
    class OpenGLShaders : public ShadersImpl
    {
    public:
        OpenGLShaders();
        OpenGLShaders(const std::string& vertexSFile, const std::string& fragementSFile);
        virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragementSFile) override;
        virtual void Bind() override;
        virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) override;
        virtual void SetIntUniform(const std::string& uniformName, int value) override;
        
        ~OpenGLShaders();
        
    private:
        unsigned int mShaders{ 0 };
        
        virtual std::string ReadFile(const std::string& fileName) override;
    };
}

#endif /* OpenGLShaders_hpp */
