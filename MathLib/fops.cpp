#include "fops.h"
#include <cmath>
#include <cfloat>

// FLT_EPSILON in <cfloat> is an okay threshold.
// float equivalence
// We want to see if two floats are negligbly close
// enough to be considered the same.
bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.00001f;
}

float deg2rad(float deg)
{
	return 0.0174533 * deg;
}

float rad2deg(float rad)
{
	return 57.2958 * rad;
}

float linearHalf(float x)
{
	return 0.5f*x;
}

float growfast(float x)
{
	return x*x*x*x;
}

float growslow(float x)
{
	return 1 - growfast(1 - x);
}

float hardAngle(float x)
{
	if (x <= 0.5)
		return 2 * x;
	else
	return -2 *(x-1);
}

float bounce(float x)
{
	return abs(cos(x*10)*(1-x));
}

float bounceflip(float x)
{
	return 1-bounce(x);
}

float parabola(float x)
{
	return -(x - .5) * 2 + 1;
}

float parabflip(float x)
{
	return 1 - parabola(x);
}


/*
a. is probably something like a quadratic.
b. is probably something like the rev quadratic

c.
when x 0-0.5 : y = 1 - 0, when x 0.5-1 : y = 1 - 0;

*/