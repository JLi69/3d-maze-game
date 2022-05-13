#version 330 core

layout(location = 0) in vec4 position;

out vec4 outCol;

//Perspective matrix
uniform mat4 u_Perspective;

uniform mat4 u_ModelViewMatrix;

void main()
{
	gl_Position = u_Perspective * u_ModelViewMatrix * position;

	outCol = vec4(position.xyz, 1.0) * 0.5 + vec4(0.5, 0.5, 0.5, 0.5);
}