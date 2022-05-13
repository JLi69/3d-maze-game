#include "GL-utils/Shader.h"
#include "GL-utils/VertexBuffer.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <vector>
#include <stack>

class Engine
{
	GLFWwindow* glWindow;
	
	VertexBuffer vb;
	Shader sh;
	Shader rainbowSh;

	//Matrices
	glm::mat4 perspectiveMatrix;

	//Camera location
	glm::vec3 cameraPosition;
	//Camera movement vector
	glm::vec3 cameraMovement;
	//Camera rotation (in radians)
	float cameraRotation = 0.0f, rotationSpeed = 0.0f;

	float timeToDrawFrame = 1.0f;

	//Level data 
	std::vector<glm::vec3> maze; //Store the positions of the walls here
	std::vector<glm::vec3> coins; //Store the positions of coins here
	glm::vec3 exitPos; //Store the position of the exit here

	//Size of the map
	const float wallSize = 2.5f;
	const float mapXSize = 32.0f * wallSize, mapZSize = 32.0f * wallSize;
	const float playerSpeed = 10.0f, playerRotationSpeed = 1.6f;

	float theta = 0.0f;

	//Draw and update the scene
	void Draw();
	void Update();

	//Handle key input from the user
	void HandleKeyInput(GLFWwindow* win, int key, int scancode, int action, int mods);
	//Window resizing
	void HandleWindowResize(GLFWwindow* win, int newWidth, int newHeight);

	//Read a level file
	bool ReadLevelFile(std::string filename);

	//Generate a maze
	void GenerateMaze();
public:
	//Main loop
	void Run();

	//Constructor
	Engine();
};
