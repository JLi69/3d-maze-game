#include "Engine.h"

void Engine::Update()
{
	cameraPosition += cameraMovement * timeToDrawFrame;
	if(cameraPosition.x < -mapXSize || cameraPosition.x > mapXSize || cameraPosition.z < -mapZSize || cameraPosition.z > mapZSize)
	{
		cameraPosition.x -= cameraMovement.x * timeToDrawFrame;
		cameraPosition.z -= cameraMovement.z * timeToDrawFrame;
	}

	cameraRotation += rotationSpeed * timeToDrawFrame;

	theta += timeToDrawFrame;

	//Handle wall collision
	for(auto w : maze)
	{
		if(cameraPosition.x > w.x - wallSize - 0.1f && cameraPosition.x < w.x + wallSize + 0.1f &&
			cameraPosition.z > w.z - wallSize - 0.1f && cameraPosition.z < w.z + wallSize + 0.1f)
		{
			cameraPosition.x -= cameraMovement.x * timeToDrawFrame;
			cameraPosition.z -= cameraMovement.z * timeToDrawFrame;
			break;
		}
	}

	//Check to see if the player found the exit
	glm::vec3 distanceToExit = exitPos - cameraPosition;
	if(glm::sqrt(distanceToExit.x * distanceToExit.x + distanceToExit.y * distanceToExit.y + distanceToExit.z * distanceToExit.z) < 1.0f)
	{
		GenerateMaze();
		return;
	}

	//Check to see if the player collided with a coin
	for(std::vector<glm::vec3>::iterator it = coins.begin(); it != coins.end(); it++)
	{
		glm::vec3 tempCoin = *it;
		glm::vec3 distanceToCoin = tempCoin - cameraPosition;
		if(glm::sqrt(distanceToCoin.x * distanceToCoin.x + distanceToCoin.y * distanceToCoin.y + distanceToCoin.z * distanceToCoin.z) < 2.0f)
		{
			coins.erase(it);
			break;
		}
	}

	//Have gravity affect the camera
	if(cameraPosition.y > 2.5f)
	{
		cameraMovement.y -= 22.0f * timeToDrawFrame;
	}
	else if(cameraPosition.y <= 2.5f)
	{
		cameraPosition.y = 2.5f;
		cameraMovement.y = 0.0f;
	}

	glfwPollEvents();
}
