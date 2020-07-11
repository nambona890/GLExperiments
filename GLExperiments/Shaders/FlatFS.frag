#version 330 core

out vec4 FragColor;
in vec3 colout;

void main()
{
	FragColor = vec4(colout,1.0);
}