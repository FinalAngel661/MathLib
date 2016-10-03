#include "fops.h"
#include <cmath>
#include <cfloat>
#include "Vec2.h"

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

float parabola1(float x1, float x2,float x)
{
	return x1*2+x2+x;
}

float parabflip(float x)
{
	return 1 - (2*x-1)*(2*x-1);
}

float lerp(float start, float end, float alpha)
{
	//avoids some issues with floating point errors!
	return (1 - alpha)*start + (alpha)*end;

	//slope intercept form,where alpha is x
	//y=m*x+b
	//return alpha*(end - start) + start;

}

float QuadBezier(float start, float mid, float end, float alpha)
{
	return lerp(lerp(start, mid, alpha), lerp(mid,end,alpha),alpha);
}

float hermitSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00*start+h10*s_tan + h01*end+h11*e_tan;
}

float cardinalSpline(float start, float mid, float end, float tightness,float alpha)
{
	float s_tan = (mid - start) * tightness, e_tan = (end - mid)*tightness;
	return hermitSpline(start,s_tan,end,e_tan,alpha);
}

float catRomPline(float start, float mid, float end,float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}


//
//vec2 lerpp(vec2 a_A, vec2 a_B, float a_t)
//{
//
//
//}
//
//vec2 QuadBezier(vec2 a_A, vec2 a_B, vec2 a_C, float a_t)
//{
//	vec2 mid1 = lerpp(a_A, a_B, a_t);
//
//}
//
//vec2 CardinalSpline(vec2 point0, vec2 point1,vec2 point2,float a,float b)
//{
//	//vec2 tangent0 =
//
//}



/*
a. is probably something like a quadratic.
b. is probably something like the rev quadratic

c.
when x 0-0.5 : y = 1 - 0, when x 0.5-1 : y = 1 - 0;

*/