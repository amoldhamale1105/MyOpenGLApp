#pragma once
#include "Light.hpp"
#include <vector>
#include "OmniShadowMap.hpp"

#define MAX_POINT_LIGHTS 3

class PointLight : public Light
{
    public:
        PointLight();
        PointLight(GLuint shadowWidth, GLuint shadowHeight,
                GLfloat near, GLfloat far,
                GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                GLfloat xPos, GLfloat yPos, GLfloat zPos,
                GLfloat con, GLfloat lin, GLfloat exp);
        virtual ~PointLight();

        void UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                        GLuint diffuseIntensityLocation, GLuint positionLocation,
                        GLuint conLocation, GLuint linLocation, GLuint expLocation);

        std::vector<glm::mat4> CalculateLightTransform();

        GLfloat GetFarPlane() const { return farPlane; }
        glm::vec3 GetPosition() const { return position; }

    protected:
        glm::vec3 position;
        GLfloat constant, linear, exponent;
        GLfloat farPlane;
};
