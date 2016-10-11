#pragma once
#include "vec3.h"

union mat4
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat4 mat4Identity();
mat4 transpose(const mat4 &A);

bool operator != (const mat4 &A, const mat4 &B);
bool operator==(const mat4 &A, const mat4 &B);
mat4 operator+(const mat4 &A, const mat4 &B);
mat4 transpose(const mat4 &A);

mat4 operator-(const mat4 &A, const mat4 &B);
mat4 operator-(const mat4 &A);

mat4 operator*(const mat4 &A, float s);
mat4 operator*(float s, const mat4 &A);
mat4 operator*(const mat4 &A, const mat4 &B);
mat4 operator*(const mat4 &A, const vec3 &V);

float determinant(const mat4 &A);
mat4 inverse(const mat4 &A);
