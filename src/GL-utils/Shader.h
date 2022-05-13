#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "HandleGLError.h"

class ShaderSrc
{
	std::string src;
	unsigned int shaderId;
public:
	//Error handling
	void PrintShaderErrorLog();

	//Get source code from a file
	bool ReadFile(std::string filename);

	//Compile the shader
	//Returns the id that OpenGL gives the compiled shader
	unsigned int CompileSrc(GLenum shaderType);
};

class Shader
{
	ShaderSrc vert, frag;
	unsigned int programId; //ID for the program
public:
	//Error handling
	void PrintProgramErrorLog();

	unsigned int GetId();

	//Get the location of a uniform
	int GetUniformLocation(std::string uniformName);

	//Constructor
	Shader(std::string vertFile, std::string fragFile, bool use);

	//Default constructor
	Shader();
};