#include "Engine.h"

void Engine::HandleKeyInput(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS)
	{
		switch(key)
		{
		//Move around
		case GLFW_KEY_UP:
			cameraMovement.x = playerSpeed * glm::sin(cameraRotation);
			cameraMovement.z = playerSpeed * -glm::cos(cameraRotation);
			break;
		case GLFW_KEY_DOWN:
			cameraMovement.x = playerSpeed * -glm::sin(cameraRotation);
			cameraMovement.z = playerSpeed * glm::cos(cameraRotation);
			break;
		//Rotate the camera
		case GLFW_KEY_LEFT:
			rotationSpeed = -playerRotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationSpeed = playerRotationSpeed;
			break;
		//Jump
		case GLFW_KEY_SPACE:
			if(cameraPosition.y <= 2.5f)
				cameraMovement.y = 10.0f;
			break;
		}
	}
	else if(action == GLFW_RELEASE)
	{
		switch(key)
		{
		//Stop moving
		case GLFW_KEY_UP:
			cameraMovement.x = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		case GLFW_KEY_DOWN:
			cameraMovement.x = 0.0f;
			cameraMovement.z = 0.0f;
			break;
		//Stop rotating the camera the camera
		case GLFW_KEY_LEFT:
			rotationSpeed = 0.0f;
			break;
		case GLFW_KEY_RIGHT:
			rotationSpeed = 0.0f;
			break;
		}
	}
}