#pragma once

#include <iostream>
#include <string.h>
#include <fstream>

#include<GL/glew.h>

class Shader
{
    public:
        Shader();
        ~Shader();
        void CreateFromString(const char* vertexCode, const char* fragmentCode);
        void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

        std::string ReadFile(const char* fileLocation);

        GLuint GetProjectionLocation() const;
        GLuint GetModelLocation() const;
        GLuint GetViewLocation() const;
        GLuint GetAmbientIntensityLocation() const;
        GLuint GetAmbientColorLocation() const;
        GLuint GetDiffuseIntensityLocation() const;
        GLuint GetDirectionLocation() const;
        GLuint GetEyePositionLocation() const { return uniformEyePosition; }
        GLuint GetSpecularIntensityLocation() const { return uniformSpecularIntensity; }
        GLuint GetShininessLocation() const { return uniformShininess; }

        void UseShader();
        void ClearShader();
    
    private:
        GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
            uniformAmbientIntensity, uniformAmbientColor, uniformDiffuseIntensity, uniformDirection,
            uniformSpecularIntensity, uniformShininess;

        void CompileShader(const char* vertexCode, const char* fragmentCode);
        void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};;