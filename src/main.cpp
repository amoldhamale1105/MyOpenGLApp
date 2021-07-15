#define _USE_MATH_DEFINES
#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"
#include "Light.hpp"
#include "Material.hpp"

const float toRadians = M_PI / 180.f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader*> shaderList;
Camera camera;

Texture brickTexture;
Texture dirtTexture;

Material shinyMaterial;
Material dullMaterial;

Light mainLight;

GLfloat deltaTime = 0.f;
GLfloat lastTime = 0.f;

//Vertex shader
static const char* vShader = "shaders/shader.vert";

//Fragment shader
static const char* fShader = "shaders/shader.frag";

void calcAverageNormals(unsigned int* indices, unsigned int indexCount, GLfloat* vertices, unsigned int vertexCount, unsigned int vLength, unsigned int normalOffset)
{
	for(size_t i = 0; i < indexCount; i+=3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i+1] * vLength;
		unsigned int in2 = indices[i+2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1+1] - vertices[in0+1], vertices[in1+2] - vertices[in0+2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2+1] - vertices[in0+1], vertices[in2+2] - vertices[in0+2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0+1] += normal.y; vertices[in0+2] += normal.z;
		vertices[in1] += normal.x; vertices[in1+1] += normal.y; vertices[in1+2] += normal.z;
		vertices[in2] += normal.x; vertices[in2+1] += normal.y; vertices[in2+2] += normal.z;
	}

	for(size_t i = 0; i < vertexCount/ vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset+1], vertices[nOffset+2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset+1] = vec.y; vertices[nOffset+2] = vec.z;
	}
}

void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};
	/**
	 * x, y, z are the pyramid vertices and u, v are texture co-ordinates
	 * Range of tex co-ordinates is between 0 to 1
	 * Tex coords origin at bottom left with u, v as 0, 0
	 **/
	GLfloat vertices[] = {
	//	x		y		z		u		v		nx		ny		nz
		-1.0f, -1.0f, -0.6f, 	0.f,	0.f,	0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 1.0f,		0.5f,	0.f,	0.0f, 0.0f, 0.0f,
		1.0, -1.0f, -0.6f,		1.f,	0.f,	0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,		0.5f,	1.f,	0.0f, 0.0f, 0.0f
	};

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);
}

void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(shader1);
}

int main(int argc, char** argv)
{
	mainWindow = Window(1366, 768);
	mainWindow.initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f), -90.f, 0.f, 5.f, 0.5f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTexture();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTexture();

	shinyMaterial = Material(1.0f, 32);
	dullMaterial = Material(0.3f, 4);

	mainLight = Light(1.0f, 1.0f, 1.0f, 0.2f, 2.0f, -1.0f, -2.0f, 0.3f);

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0, 
		uniformAmbientColor = 0, uniformAmbientIntensity = 0, uniformDirection = 0, uniformDiffuseIntensity = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);

	//Loop until window closed
	while(!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime(); //If using SDL, SDL_GetPerformanceCounter();
		deltaTime = now - lastTime;
		lastTime = now;

		//Get + Handle user input events
		glfwPollEvents();

		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderList[0]->UseShader();
		uniformModel = shaderList[0]->GetModelLocation();
		uniformProjection = shaderList[0]->GetProjectionLocation();
		uniformView = shaderList[0]->GetViewLocation();
		uniformAmbientColor = shaderList[0]->GetAmbientColorLocation();
		uniformAmbientIntensity = shaderList[0]->GetAmbientIntensityLocation();
		uniformDirection = shaderList[0]->GetDirectionLocation();
		uniformDiffuseIntensity = shaderList[0]->GetDiffuseIntensityLocation();
		uniformEyePosition = shaderList[0]->GetEyePositionLocation();
		uniformSpecularIntensity = shaderList[0]->GetSpecularIntensityLocation();
		uniformShininess = shaderList[0]->GetShininessLocation();

		mainLight.UseLight(uniformAmbientIntensity, uniformAmbientColor, uniformDiffuseIntensity, uniformDirection);

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(0.f, 0.f, -2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		brickTexture.UseTexture();
		shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[0]->RenderMesh();

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.f, 4.f, -2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		dirtTexture.UseTexture();
		dullMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[1]->RenderMesh();
		
		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
