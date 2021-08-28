#pragma once

#include <vector>
#include <string>
#include "Texture.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.hpp"
#include "Shader.hpp"

class Skybox
{
    public:
        Skybox();
        Skybox(std::vector<std::string> faceLocations);
        ~Skybox();

        void DrawSkybox(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

    private:
        Mesh* skyMesh;
        Shader* skyShader;

        GLuint textureId;
        GLuint uniformProjection, uniformView;
};