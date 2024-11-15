//
//  OpenGLShaders.hpp
//  Tomato
//
//  Created by Game on 11/14/24.
//

#ifndef OpenGLShaders_hpp
#define OpenGLShaders_hpp

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
        
        ~OpenGLShaders() {};
    };
}

#endif /* OpenGLShaders_hpp */
