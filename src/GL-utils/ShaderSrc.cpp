#include "Shader.h"

void ShaderSrc::PrintShaderErrorLog()
{
	int length, chWritten;
	char* msg;
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
	if(length > 0)
	{
		msg = new char[length];

		glGetShaderInfoLog(shaderId, length, &chWritten, msg);
		std::cout << "Shader info log: " << msg << std::endl;

		delete msg;
	}
}

bool ShaderSrc::ReadFile(std::string filename)
{
	std::ifstream shaderFile(filename);

	//Check to see if the file is open
	if(!shaderFile.is_open())
	{
		std::cout << "ERROR: Failed to open file!" << std::endl;
		std::cout << "Attempted to open file: " << filename << std::endl;
		return false;
	}

	std::stringstream fileSource;
	std::string line;

	//Read the file
	while(std::getline(shaderFile, line)) fileSource << line << '\n';

	this->src = fileSource.str();

	return true; //Sucessfully opened and read file
}

unsigned int ShaderSrc::CompileSrc(GLenum shaderType)
{
	unsigned int id = glCreateShader(shaderType); //Create the shader
	int compileStatus; //Store the compile status here
	
	const char* begin = &src[0]; //Get the pointer to the beginning of the shader source code
	glShaderSource(id, 1, &begin, nullptr); //Get the shader source code
	glCompileShader(id); //Compile the shader

	shaderId = id;

	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
	//Failed to compile sucessfully
	if(compileStatus != 1)
	{
		//Print out error message
		switch(shaderType)
		{
		case GL_VERTEX_SHADER:
			std::cout << "vertex";
			break;
		case GL_FRAGMENT_SHADER:
			std::cout << "fragment";
			break;
		}

		std::cout << " shader compilation failed." << std::endl;
		PrintShaderErrorLog();
	}

	return id;
}