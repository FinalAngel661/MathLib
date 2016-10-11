#pragma once
#include "vec3.h"

union mat5
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat5 mat5Identity();
mat5 transpose(const mat5 &A);

bool operator != (const mat5 &A, const mat5 &B);
bool operator==(const mat5 &A, const mat5 &B);
mat5 operator+(const mat5 &A, const mat5 &B);
mat5 transpose(const mat5 &A);

mat5 operator-(const mat5 &A, const mat5 &B);
mat5 operator-(const mat5 &A);

mat5 operator*(const mat5 &A, float s);
mat5 operator*(float s, const mat5 &A);
mat5 operator*(const mat5 &A, const mat5 &B);
mat5 operator*(const mat5 &A, const vec3 &V);

float determinant(const mat5 &A);
mat5 inverse(const mat5 &A);
