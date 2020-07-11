#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

struct Vec2
{
	double x;
	double y;
};

struct Vec3
{
	double x;
	double y;
	double z;
};

struct Vec4
{
	double x;
	double y;
	double z;
	double w = 1;
};

struct Vec4C
{
	double x;
	double y;
	double z;
	double w = 1;
	double r;
	double g;
	double b;
};

struct Vec4T
{
	double x;
	double y;
	double z;
	double w = 1;
	double u;
	double v;
};