#pragma once
#include "common.h"

class NamWindow
{
public:
	NamWindow();
	int Start();
private:
	int sWidth = SCREENWIDTH;
	int sHeight = SCREENHEIGHT;
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
    Vec2 pMouse;

    Vec2 tl = { -2.0,-1.0 };
    Vec2 br = { 1.0, 1.0 };
    Vec2 scale = { 1.0,1.0 };
    Vec2 offset = { 0.0,0.0 };

    Vec4T triangle[24] = {
        -1.0, 1.0, 0.0, 1.0,     tl.x, tl.y,
        1.0, -1.0, 0.0f, 1.0,       br.x, br.y,
        1.0, 1.0, 0.0f, 1.0,      br.x, tl.y,
        -1.0, -1.0, 0.0f, 1.0,      tl.x, br.y,
    };

    unsigned int triangleInd[6] = {
        0,2,3,
        1,2,3
    };

    Vec2 ScreenNormalize(const Vec2& v)
    {
        return { (v.x / (sWidth / 2)) - 1,(v.y / (sHeight / 2)) - 1 };
    }

    Vec2 WtS(const Vec2& v)
    {
        return {    (v.x - offset.x) * scale.x,
                    (v.y - offset.y) * scale.y };
    }

    Vec2 StW(const Vec2& v)
    {
        return {    (v.x / scale.x) + offset.x,
                    (v.y / scale.y) + offset.y };
    }
};