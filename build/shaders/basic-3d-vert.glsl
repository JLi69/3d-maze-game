#version 330 core

layout(location = 0) in vec4 position;

//Perspective matrix
uniform mat4 u_Perspective;

uniform mat4 u_ModelViewMatrix;

out float shading;

void main()
{
	gl_Position = u_Perspective * u_ModelViewMatrix * position;

	if(position.x < 0.0 && position.z < 0.0 || position.x > 0.0 && position.z > 0.0)
	{
		shading = 0.75;
	}
	else
	{
		shading = 1.0;
	}
}