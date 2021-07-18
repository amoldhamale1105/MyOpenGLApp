#pragma once
#include "Light.hpp"

#define MAX_POINT_LIGHTS 3

class PointLight : public Light
{
    public:
        PointLight();
        PointLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                GLfloat xPos, GLfloat yPos, GLfloat zPos,
                GLfloat con, GLfloat lin, GLfloat exp);
        ~PointLight();

        void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation,
                        GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                        GLfloat conLocation, GLfloat linLocation, GLfloat expLocation);

    private:
        glm::vec3 position;
        GLfloat constant, linear, exponent;
};
