#version 330 core

uniform vec4 u_Color; 

in float shading;

out vec4 color;

void main()
{
	color = u_Color * shading;
}