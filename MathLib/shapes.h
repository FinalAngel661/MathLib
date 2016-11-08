#pragma once
#include "Mat3.h"

//Boundign Volumes
//Base stete of a more complex code.
struct Circle
{
public:
	vec2 pos;
	float rad;
};

Circle operator*(const mat3 &T, const Circle &C);

bool operator==(const Circle &A, const Circle &B);

struct AABB 
{
	vec2 pos, he;

	vec2 min() const;
	vec2 max() const;
};
struct Plane 
{
	vec2 pos, dir;
};

struct Ray {};
struct Hull 
{
	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;

	Hull(const vec2 *vertices, unsigned vsize);

};


Circle operator*(const mat3 &T, const Circle &C);
AABB operator*(const mat3 &T, const AABB &B);
Plane operator*(const mat3 &T, const Plane &P);
Ray operator*(const mat3 &T, const Ray &R);

Hull operator*(const mat3 &T, const Hull &H);
bool operator==(const Hull &A, const Hull &B);