cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME MyOpenGLApp)

project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)
set(CMAKE_EXE_LINKER_FLAGS 
          "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,/usr/local/lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (glm REQUIRED)
find_package (GLEW REQUIRED STATIC)
find_package (assimp)

pkg_search_module(GLFW REQUIRED glfw3)
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
)

add_executable(${PROJECT_NAME} src/main.cpp ${PROJECT_SOURCES})
target_link_libraries (${PROJECT_NAME} 
        ${OPENGL_LIBRARIES} 
        ${GLFW_STATIC_LIBRARIES}
        ${GLEW_LIBRARIES} 
        ${ASSIMP_LIBRARIES}
        X11 Xxf86vm pthread Xrandr Xinerama Xi Xcursor)