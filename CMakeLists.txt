cmake_minimum_required(VERSION 3.0.0)

project(OpenGLApp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (glm REQUIRED)
find_package (GLEW REQUIRED STATIC)

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS} include shaders)

set(PROJECT_SOURCES 
        src/Mesh.cpp
        src/Shader.cpp
        src/Window.cpp
        src/Camera.cpp
        src/Texture.cpp
        src/Light.cpp
)

add_executable(OpenGLApp src/main.cpp ${PROJECT_SOURCES})
target_link_libraries (OpenGLApp 
        ${OPENGL_LIBRARIES} 
        ${GLFW_STATIC_LIBRARIES}
        ${GLEW_LIBRARIES} 
        X11 Xxf86vm pthread Xrandr Xinerama Xi Xcursor)

