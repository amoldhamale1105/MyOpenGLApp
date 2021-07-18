#pragma once

#include <iostream>
#include <string.h>
#include <fstream>

#include<GL/glew.h>

#include "DirectionalLight.hpp"
#include "PointLight.hpp"

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

        void SetDirectionalLight(DirectionalLight* dLight);
        void SetPointLight(PointLight* pLight, unsigned int lightCount);

        void UseShader();
        void ClearShader();
    
    private:
        int pointLightCount;

        GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
            uniformSpecularIntensity, uniformShininess;
        
        struct 
        {
            GLuint uniformColor;
            GLuint uniformAmbientIntensity;
            GLuint uniformDiffuseIntensity;

            GLuint uniformDirection;
        } uniformDirectionalLight;

        GLuint uniformPointLightCount;

        struct 
        {
            GLuint uniformColor;
            GLuint uniformAmbientIntensity;
            GLuint uniformDiffuseIntensity;

            GLuint uniformPosition;
            GLuint uniformConstant;
            GLuint uniformLinear;
            GLuint uniformExponent;
        } uniformPointLight[MAX_POINT_LIGHTS];

        void CompileShader(const char* vertexCode, const char* fragmentCode);
        void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};;