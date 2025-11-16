cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME MyOpenGLApp)

project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Program Files/vcpkg/installed/x64-windows/share")
endif(WIN32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package (OpenGL REQUIRED)
find_package (glm REQUIRED)
find_package (GLEW REQUIRED STATIC)
find_package (assimp)
find_package (glfw3 REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS} ${ASSIMP_INCLUDE_DIRS} include shaders)

set(PROJECT_SOURCES 
        src/Mesh.cpp
        src/Shader.cpp
        src/Window.cpp
        src/Camera.cpp
        src/Texture.cpp
        src/Light.cpp
        src/Material.cpp
        src/DirectionalLight.cpp
        src/PointLight.cpp
        src/SpotLight.cpp
        src/Model.cpp
        src/ShadowMap.cpp
        src/OmniShadowMap.cpp
        src/Skybox.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${PROJECT_SOURCES})
target_link_libraries (${PROJECT_NAME} 
        ${OPENGL_LIBRARIES} 
        glfw
        ${GLEW_LIBRARIES} 
        ${ASSIMP_LIBRARIES})