# OpenGLApp
A graphical app with 3D models generated natively and imported externally using OpenGL  
The project is configured with cmake build system  
Generated with the OpenGL base public template (https://github.com/amoldhamale1105/OpenGLBase.git)  
Currently linked with the glew, glfw and glm libraries    
Please note that the glew and glfw libs are linked statically and thus necessitate installation in the /usr dir beforehand through their source code. Please refer to the CMakeLists.txt for a better understanding  

## Build instructions
Run `cmake ..` from the build dir or reconfigure all if loaded in VSCode  
Run `make` or **build all** if loaded in VSCode  
The generated binary must be present in the bin dir on a successful build

## Output
The following scene should be visible in a window if the generated binary runs successfully with all its dependencies  
Navigate the scene with keys A, W and D and the mouse for looking around  
*A spotlight can be turned on for fun with the key L to test reflections and omnidirectional shadows*

![MyOpenGLApp_view1](https://user-images.githubusercontent.com/78597991/177564164-0cd2e6ed-14a7-4d9b-b6e5-226f3eebfdfb.png)
![MyOpenGLApp_view2](https://user-images.githubusercontent.com/78597991/177564519-81df1753-0cb3-4c81-8e64-f5e64c8fc077.png)
![MyOpenGLapp_view3](https://user-images.githubusercontent.com/78597991/177564529-4e60d18e-2ca4-47a3-a5a0-4a18fd729263.png)
![MyOpenGLApp_view4](https://user-images.githubusercontent.com/78597991/177564541-a64283e0-416b-440e-b878-e22958052e03.png)
