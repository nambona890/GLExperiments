#version 330 core
#extension GL_ARB_gpu_shader_fp64 : enable

out vec4 FragColor;
in highp vec2 uv;
uniform int iterations;

void main()
{
	//FragColor = vec4(0.5 * sin(uv.x) + 0.5,0.5 * sin(uv.y) + 0.5, 1.0, 1.0);
	highp double re = 0;
	highp double im = 0;
	highp double cr = uv.x;
	highp double ci = uv.y;
	highp double zr = 0;
	highp double zi = 0;
	int n = 0;
	while((zr * zr + zi * zi) < 4.0 && n < iterations)
	{
		re = zr * zr - zi * zi + cr;
		im = zr * zi * 2.0 + ci;
		zr = re;
		zi = im;
		n++;
	}
	float a = 0.1;
	float nf = n;
	FragColor = vec4(0.5 * sin(a * nf) + 0.5, 0.5 * sin(a * nf + 2.094) + 0.5,  0.5 * sin(a * nf + 4.188) + 0.5, 1.0);
}