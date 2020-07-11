#version 330 core

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec2 aUV;

out vec2 UV;

void main()
{
	gl_Position = aPos;
	UV = vec2(aUV.x,aUV.y);
}