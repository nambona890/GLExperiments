#version 330 core
#extension GL_ARB_gpu_shader_fp64 : enable

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec2 aUV;
uniform vec2 offset;
uniform vec2 scalar;
out vec2 uv;

void main()
{
	gl_Position = aPos;
	uv = aUV;
}