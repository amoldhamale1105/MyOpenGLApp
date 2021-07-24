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
        virtual ~PointLight();

        void UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                        GLuint diffuseIntensityLocation, GLuint positionLocation,
                        GLuint conLocation, GLuint linLocation, GLuint expLocation);

    protected:
        glm::vec3 position;
        GLfloat constant, linear, exponent;
};
