#pragma once

#include <iostream>
#include <GL/glew.h>

#include "stb_image.h"

class Texture
{
    public:
        Texture();
        Texture(const std::string& fileLocation);
        ~Texture();

        void LoadTexture();
        void UseTexture();
        void ClearTexture();

    private:
        GLuint textureID;
        int width, height, bitDepth;

        std::string fileLocation;
};