#pragma once
#include "common.h"

class Surface
{
public:
	int width, height, channels;
	unsigned int texture;
	unsigned char* data;
	Surface(std::string filename);
	//void Bind();
};