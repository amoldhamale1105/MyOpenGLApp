#include "../include/PointLight.hpp"

PointLight::PointLight() : Light()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    constant = 1.0f;
    linear = 0.0f;
    exponent = 0.0f;
}

PointLight::PointLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                    GLfloat xPos, GLfloat yPos, GLfloat zPos,
                    GLfloat con, GLfloat lin, GLfloat exp) : Light(red, green, blue, aIntensity, dIntensity)
{
    position = glm::vec3(xPos, yPos, zPos);
    constant = con;
    linear = lin;
    exponent = exp;
}

PointLight::~PointLight()
{

}

void PointLight::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColorLocation,
                        GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                        GLfloat conLocation, GLfloat linLocation, GLfloat expLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);

    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(conLocation, constant);
    glUniform1f(linLocation, linear);
    glUniform1f(expLocation, exponent);
}