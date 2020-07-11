#pragma once
#include "common.h"

GLuint CreateShader(const std::string& filename, GLenum shadertype)
{
	std::ifstream file(filename);
	std::stringstream buffer;
	if (file.is_open())
	{
		buffer << file.rdbuf();
		file.close();
	}
	else
	{
		std::string ex = "Could not open ";
		ex.append(filename);
		throw std::exception(ex.c_str());
	}
	GLuint shader = glCreateShader(shadertype);
	std::string output = buffer.str();
	const char* shadersourcestrings = output.c_str();
	
	glShaderSource(shader, 1, &shadersourcestrings, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(shader, 512, NULL, infoLog);
	std::cout << filename << "\n" << "Shader compilation:\n\n" << infoLog << std::endl;

	return shader;
}

GLuint CreateProgram(unsigned int& vS, unsigned int& fS)
{
	unsigned int program = glCreateProgram();
	glAttachShader(program, vS);
	glAttachShader(program, fS);
	glLinkProgram(program);
	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	glGetProgramInfoLog(program, 512, NULL, infoLog);
	std::cout << "Program linking:\n\n" << infoLog << std::endl;
	glDeleteShader(vS);
	glDeleteShader(fS);
	return program;
}