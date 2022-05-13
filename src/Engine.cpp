#include "Engine.h"

void Engine::Run()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	while(!glfwWindowShouldClose(glWindow))
	{
<<<<<<< HEAD
		std::chrono::time_point start = std::chrono::system_clock::now();
		Draw(); //Draw the frame
		Update(); //Update the frame
		std::chrono::time_point end = std::chrono::system_clock::now();
=======
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
		Draw(); //Draw the frame
		Update(); //Update the frame
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
>>>>>>> master
		std::chrono::duration<float> duration = end - start;
		
		timeToDrawFrame = duration.count(); //Get how long it took to draw/update the frame
	}
	glfwTerminate(); //Free up resources used by glfw
}

Engine::Engine()
{
	//Set a random seed for the random number generator
	srand(time(NULL));

	//Initialize GLFW
	if(!glfwInit()) exit(-1);

	//Create the window
	glWindow = glfwCreateWindow(1920, 1080, "3d maze game", NULL, NULL);
	if(!glWindow)
	{
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(glWindow);

	//Initialize glad
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) exit(-1);

	//Set up the matrices
	//Set up the perspective matrix
	//FOV
<<<<<<< HEAD
	const float fov = 60.0f;
=======
	const float fov = 75.0f;
>>>>>>> master
	//Screen dimensions
	int width, height;
	glfwGetWindowSize(glWindow, &width, &height);
	//Calculate the aspect ratio
	float aspect = (float)width / (float)height;
	perspectiveMatrix = glm::perspective(3.1415926535f / 180.0f * fov, aspect, 0.01f, 1000.0f);

	glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	//Cube
	float cube[] = 
	{
		-1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
    	1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f
	};
	//Set up the vertex buffer and the shader
	vb = VertexBuffer(&cube[0], sizeof(cube), 3, true);
	sh = Shader("shaders/basic-3d-vert.glsl", "shaders/basic-frag.glsl", false);
	rainbowSh = Shader("shaders/rainbow-vert.glsl", "shaders/rainbow-frag.glsl", false);

	//Set up the camera
	cameraPosition = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraMovement = glm::vec3(0.0f, 0.0f, 0.0f);

	//Set up key input
	glfwSetWindowUserPointer(glWindow, this);
	auto HandleKeyInputFunc = [](GLFWwindow* win, int key, int scancode, int action, int mods)
	{
		static_cast<Engine*>(glfwGetWindowUserPointer(win))->HandleKeyInput(win, key, scancode, action, mods);
	};
	glfwSetKeyCallback(glWindow, HandleKeyInputFunc);
<<<<<<< HEAD

	GenerateMaze();
}
=======
	//Handle window resizing
	auto HandleResizeFunc = [](GLFWwindow* win, int newWidth, int newHeight)
	{
		static_cast<Engine*>(glfwGetWindowUserPointer(win))->HandleWindowResize(win, newWidth, newHeight);
	};
	glfwSetWindowSizeCallback(glWindow, HandleResizeFunc);

	GenerateMaze();
}
>>>>>>> master
