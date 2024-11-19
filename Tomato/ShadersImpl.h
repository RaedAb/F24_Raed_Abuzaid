//
//  ShadersImpl.h
//  Tomato
//
//  Created by Game on 11/14/24.
//

#ifndef ShadersImpl_h
#define ShadersImpl_h
#include "pch.h"

namespace Tmt
{
    class ShadersImpl
    {
    public:
        virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragementSFile) = 0;
        virtual void Bind() = 0;
        virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) = 0;
        virtual void SetIntUniform(const std::string& uniformName, int value) = 0;
        virtual std::string ReadFile(const std::string& fileName) = 0;
        
        virtual ~ShadersImpl() {};
        
    };
}


#endif /* ShadersImpl_h */
