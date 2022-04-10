#include "Shader.h"

int Shader::GetUniformLocation(std::string uniformName)
{
	return glGetUniformLocation(programId, &uniformName[0]);
}

void Shader::PrintProgramErrorLog()
{
	int length, chWritten;
	char* msg;
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &length);
	if(length > 0)
	{
		msg = new char[length];

		glGetProgramInfoLog(programId, length, &chWritten, msg);
		std::cout << "Program info log: " << msg << std::endl;

		delete msg;
	}
}

unsigned int Shader::GetId()
{
	return this->programId;
}

Shader::Shader(std::string vertFile, std::string fragFile, bool use)
{
	int vsCompileStatus, fsCompileStatus, linkStatus; //Store the compile status of the shaders here

	vert.ReadFile(vertFile);
	frag.ReadFile(fragFile);

	programId = glCreateProgram();

	unsigned int vs = vert.CompileSrc(GL_VERTEX_SHADER);
	unsigned int fs = frag.CompileSrc(GL_FRAGMENT_SHADER);
	
	glAttachShader(programId, vs);
	glAttachShader(programId, fs);
	glLinkProgram(programId);

	//Check for any OpenGL errors
	GetGLErr;

	glGetProgramiv(programId, GL_LINK_STATUS, &linkStatus);
	//Failed to link
	if(linkStatus != 1)
	{
		std::cout << "linking failed." << std::endl;
		this->PrintProgramErrorLog();
	}

	glValidateProgram(programId);

	//Delete the shaders
	glDeleteShader(vs);
	glDeleteShader(fs);

	//Tell OpenGL to use the program
	if(use) glUseProgram(programId);
}

Shader::Shader()
{
	programId = 0;
}