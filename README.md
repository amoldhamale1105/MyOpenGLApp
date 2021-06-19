# OpenGLApp
A sample OpenGL app configured using cmake  
Currently linked with the glew, glfw and glm libraries  
You can use this app as a base project for OpenGL apps especially on Linux  
Please note that the glew and glfw libs are linked statically and thus necessitate installation in the /usr dir beforehand through their source code. Please refer to the CMakeLists.txt for a better understanding  

# Build instructions
Run cmake .. from the build dir or reconfigure all if loaded in VSCode  
Run make or build all if loaded in VSCode  
The generated binary must be present in the bin dir on a successful build

# Output
A blue Test Window opens with a red triangle in the middle
