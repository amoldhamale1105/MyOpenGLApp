#pragma once
#include "Light.hpp"

class DirectionalLight: public Light
{
    public:
        DirectionalLight();
        ~DirectionalLight();
        DirectionalLight(GLuint shadowWidth, GLuint shadowHeight,
                        GLfloat red, GLfloat green, GLfloat blue,
                        GLfloat aIntensity, GLfloat dIntensity,
                        GLfloat xDir, GLfloat yDir, GLfloat zDir);

        void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation,
                        GLfloat diffuseIntensityLocation, GLfloat directionLocation);

        glm::mat4 CalculateLightTransform();

    private:
        glm::vec3 direction;
};