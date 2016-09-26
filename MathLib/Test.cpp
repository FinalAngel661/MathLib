#include "Test.h"
#include <cmath>

int donothing(int x)
{
	return x*x + 2 * x + 5;
}

float quadfunc(float x)
{

	return x*x+2*x-7;
}

float quad(float a, float b, float c)
{
	return 0.f;
}

float quad_p(float a, float b, float c)
{
	return ((b - 2*b) + sqrt((b*b - 4 * a*c) / (2*a)));
}

float quad_m(float a, float b, float c)
{
	return ((b- 2*b) - sqrt((b*b - 4 * a*c) / (2* a)));
}

float lerp(float start, float end, float t)
{
	return 0.0f;
}

float distance(Point P1, Point P2)
{
	return 0.0f;
}

float distance(float x1, float y1, float x2, float y2)
{

	return 0.0f;
}


//float point_plane_distance(const Plane &p1, const Point3D &pt)
//{
//	(inner(p1.abc, pt) + p1.d)
//		sqrt(p1)
//
//}