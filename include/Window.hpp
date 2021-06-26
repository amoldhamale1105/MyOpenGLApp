#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
    public:
        Window();
        Window(GLint windowWidth, GLint windowHeight);
        ~Window();

        int initialise();

        GLfloat getBufferWidth() const {return bufferWidth;}
        GLfloat getBufferHeight() const {return bufferHeight;}

        bool getShouldClose() const {return glfwWindowShouldClose(mainWindow);}

        void swapBuffers() {glfwSwapBuffers(mainWindow);}

    private:
        GLFWwindow *mainWindow;

        GLint width, height;
        GLint bufferWidth, bufferHeight;

};