#include <glad/glad.h>
#include <iostream>

#define GetGLErr int glErr = glGetError(); while(glErr != GL_NO_ERROR) { std::cout << "glError: " << glErr << std::endl; glErr = glGetError(); }
#define GLCall(x) x; GetGLErr();