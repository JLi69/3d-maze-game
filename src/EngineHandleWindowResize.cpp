#include "Engine.h"

void Engine::HandleWindowResize(GLFWwindow* win, int newWidth, int newHeight)
{
	const float fov = 75.0f;
	//Update the aspect ratio
	float aspect;	
	if(newHeight == 0)
		aspect = 1;	
	else
		aspect = (float)newWidth / (float)newHeight;
	//Update the OpenGL viewport
	glViewport(0, 0, newWidth, newHeight);
	perspectiveMatrix = glm::perspective(3.1415926535f / 180.0f * fov, aspect, 0.1f, 1000.0f);
}
