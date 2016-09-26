#pragma once
#include <cmath>


int donothing(int x);

//prob A:
float quadfunc(float x);

//prob B:

float quad(float a, float b, float c);
float quad_p(float a, float b, float c);
float quad_m(float a, float b, float c);

//Prob C:
float lerp(float start, float end, float t);


//Prob D:
struct Point
{
	float x, y;

};
float distance(Point P1, Point P2);
float distance(float x1,float y1, float x2, float y2);


//Prob E:
struct Point3D { float x,y,z; };
float distance(Point P1, Point P2);
float distance(float x1, float y1, float z1, float x2, float y2, float z2);

// other fuctions..

//quadResults quad1(float a, float b, float c)
//{
//
//
//
//};

//struct Plane {Point3D abc};

Point3D bezier(float t, const Point3D &p1, const Point3D & p2, const Point3D &p3, const Point3D &p4)
{
	float ot = 1 - t;
	ot*ot*ot*p1.y + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p3.x;


}