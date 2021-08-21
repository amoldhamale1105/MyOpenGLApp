#include "../include/PointLight.hpp"

PointLight::PointLight() : Light()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    constant = 1.0f;
    linear = 0.0f;
    exponent = 0.0f;
}

PointLight::PointLight(GLuint shadowWidth, GLuint shadowHeight,
                    GLfloat near, GLfloat far,
                    GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
                    GLfloat xPos, GLfloat yPos, GLfloat zPos,
                    GLfloat con, GLfloat lin, GLfloat exp) : Light(shadowWidth, shadowHeight, red, green, blue, aIntensity, dIntensity)
{
    position = glm::vec3(xPos, yPos, zPos);
    constant = con;
    linear = lin;
    exponent = exp;
    farPlane = far;

    float aspect = (float)shadowWidth / (float)shadowHeight;
    lightProj = glm::perspective(glm::radians(90.0f), aspect, near, far);

    shadowMap = new OmniShadowMap();
    shadowMap->Init(shadowWidth, shadowHeight);
}

PointLight::~PointLight()
{

}

void PointLight::UseLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
                        GLuint diffuseIntensityLocation, GLuint positionLocation,
                        GLuint conLocation, GLuint linLocation, GLuint expLocation)
{
    glUniform3f(ambientColorLocation, color.x, color.y, color.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);

    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(conLocation, constant);
    glUniform1f(linLocation, linear);
    glUniform1f(expLocation, exponent);
}

std::vector<glm::mat4> PointLight::CalculateLightTransform()
{
    std::vector<glm::mat4> lightMatrices;
    
    // +x, -x
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));

    // +y, -y
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));

    // +z, -z
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
    lightMatrices.emplace_back(lightProj * glm::lookAt(position, position + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));

    return lightMatrices;
}