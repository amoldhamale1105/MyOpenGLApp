#pragma once
#include "Light.hpp"

class DirectionalLight: public Light
{
    public:
        DirectionalLight();
        ~DirectionalLight();
        DirectionalLight(GLfloat red, GLfloat green, GLfloat blue,
                        GLfloat aIntensity, GLfloat dIntensity,
                        GLfloat xDir, GLfloat yDir, GLfloat zDir);

        void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation,
                        GLfloat diffuseIntensityLocation, GLfloat directionLocation);

    private:
        glm::vec3 direction;
};