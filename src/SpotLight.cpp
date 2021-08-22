#include "../include/SpotLight.hpp"

SpotLight::SpotLight()
{
    direction = glm::vec3(0.0f, -1.0f, 0.0f);
    edge = 0.0f;
    procEdge = cosf(glm::radians(edge));
}

SpotLight::SpotLight(GLuint shadowWidth, GLuint shadowHeight,
                GLfloat near, GLfloat far,
                GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                GLfloat xPos, GLfloat yPos, GLfloat zPos,
                GLfloat xDir, GLfloat yDir, GLfloat zDir,
                GLfloat con, GLfloat lin, GLfloat exp,
                GLfloat edge) : PointLight(shadowWidth, shadowHeight, near, far, red, green, blue, aIntensity, dIntensity, xPos, yPos, zPos, con, lin, exp)
{
    direction = glm::normalize(glm::vec3(xDir, yDir, zDir));

    this->edge = edge;
    procEdge = cosf(glm::radians(edge));
}

SpotLight::~SpotLight()
{

}

void SpotLight::UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                        GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint directionLocation,
                        GLuint conLocation, GLuint linLocation, GLuint expLocation,
                        GLuint edgeLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    
    glUniform1f(ambientIntensityLocation, isFlashlightOn ? ambientIntensity : 0.0f);
    glUniform1f(diffuseIntensityLocation, isFlashlightOn ? diffuseIntensity : 0.0f);

    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(conLocation, constant);
    glUniform1f(linLocation, linear);
    glUniform1f(expLocation, exponent);

    glUniform3f(directionLocation, direction.x, direction.y, direction.z);
    glUniform1f(edgeLocation, procEdge);
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir)
{
    position = pos;
    direction = dir;
}