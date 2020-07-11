#version 330 core

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec3 aCol;

out vec3 colout;

void main()
{
	gl_Position = aPos;
	colout = aCol;
}