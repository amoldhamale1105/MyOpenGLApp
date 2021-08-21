#pragma once
#include "ShadowMap.hpp"

class OmniShadowMap : public ShadowMap
{
    public:
        OmniShadowMap();
        ~OmniShadowMap();

        bool Init(GLuint width, GLuint height) override;
        void Write() override;
        void Read(GLenum textureUnit) override;
};