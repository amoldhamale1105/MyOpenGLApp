#pragma once

#include <iostream>
#include <string.h>
#include <fstream>

#include<GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "DirectionalLight.hpp"
#include "PointLight.hpp"
#include "SpotLight.hpp"

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
        void SetSpotLight(SpotLight* sLight, unsigned int lightCount);
        void SetTexture(GLuint textureUnit);
        void SetDirectionalShadowMap(GLuint textureUnit);
        void SetDirectionalLightTransform(glm::mat4* lTransform);

        void UseShader();
        void ClearShader();
    
    private:
        int pointLightCount;
        int spotLightCount;

        GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
            uniformSpecularIntensity, uniformShininess, uniformTexture,
            uniformDirectionalLightTransform, uniformDirectionalShadowMap;
        
        struct 
        {
            GLuint uniformColor;
            GLuint uniformAmbientIntensity;
            GLuint uniformDiffuseIntensity;

            GLuint uniformDirection;
        } uniformDirectionalLight;

        GLuint uniformPointLightCount;
        GLuint uniformSpotLightCount;

        struct
        {
            GLuint uniformColor;
            GLuint uniformAmbientIntensity;
            GLuint uniformDiffuseIntensity;

            GLuint uniformPosition;
            GLuint uniformConstant;
            GLuint uniformLinear;
            GLuint uniformExponent;

            GLuint uniformDirection;
            GLuint uniformEdge;
        }uniformSpotLight[MAX_SPOT_LIGHTS];

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