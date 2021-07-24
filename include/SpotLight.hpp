#pragma once

#include "PointLight.hpp"

#define MAX_SPOT_LIGHTS 3

class SpotLight : public PointLight
{
    public:
        SpotLight();
        ~SpotLight();

        SpotLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                GLfloat xPos, GLfloat yPos, GLfloat zPos,
                GLfloat xDir, GLfloat yDir, GLfloat zDir,
                GLfloat con, GLfloat lin, GLfloat exp,
                GLfloat edge);

        void UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                        GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint directionLocation,
                        GLuint conLocation, GLuint linLocation, GLuint expLocation,
                        GLuint edgeLocation);

        void SetFlash(glm::vec3 pos, glm::vec3 dir);

    private:
        glm::vec3 direction;

        GLfloat edge, procEdge;
};