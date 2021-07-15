#include "../include/Material.hpp"

Material::Material()
{
    specularIntensity = 0.0f;
    shininess = 0.0f;
}

Material::Material(GLfloat sIntensity, GLfloat shine)
{
    specularIntensity = sIntensity;
    shininess = shine;
}

Material::~Material()
{

}

void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
    glUniform1f(specularIntensityLocation, specularIntensity);
    glUniform1f(shininessLocation, shininess);
}