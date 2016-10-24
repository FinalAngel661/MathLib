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

struct AABB {};
struct Plane {};
struct Ray {};
struct Hull {};

Circle operator*(const mat3 &T, const Circle &C);
AABB operator*(const mat3 &T, const AABB &B);
Plane operator*(const mat3 &T, const Plane &P);
Ray operator*(const mat3 &T, const Ray &R);
Hull operator*(const mat3 &T, const Hull &H);