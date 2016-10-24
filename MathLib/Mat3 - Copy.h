#pragma once

#include "vec3-Copy.h"
#include "fops-Copy.h"

union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat3 mat3Identity();
mat3 transpose(const mat3 &A);

bool operator != (const mat3 &A, const mat3 &B);
bool operator==(const mat3 &A, const mat3 &B);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 transpose(const mat3 &A);

mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A);

mat3 operator*(const mat3 &A, float s);
mat3 operator*(float s, const mat3 &A);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &V);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 scale(const vec2 &s);
mat3 translate(const vec2 &t);
mat3 rotate(const float &r);

//vec2 amul(const mat3 &A)

//the 1..
//"Affine"
//"Affine trasnsformations"