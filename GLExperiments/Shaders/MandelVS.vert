#version 330 core
#extension GL_ARB_gpu_shader_fp64 : enable

layout (location = 0) in highp vec4 aPos;
layout (location = 1) in highp vec2 aUV;
uniform vec2 offset;
uniform vec2 scalar;
out highp vec2 uv;

void main()
{
	gl_Position = aPos;
	uv = aUV;
}