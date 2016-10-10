#include "mat.h"
#include "fops.h"

vec2 mat2::operator[](unsigned idx) const
{
	return v[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return m[idx];
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return false;
}

bool operator==(const mat2 & A, const mat2 & B)
{
	return fequals(A.m[0], B.m[0]) && 
		fequals(A.m[1], B.m[1]) && 
		fequals(A.m[2], B.m[2]) && 
		fequals(A.m[3], B.m[3]);
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0],
		A.m[1] + B.m[1],
		A.m[2] + B.m[2],
		A.m[3] + B.m[3] };
}

mat2 mat2Identity()
{
	return mat2();
}

mat2 transpose(const mat2 &A)
{
	// copy the diagnal
	mat2 retval = A;

	//what values here need to change?
	// .m[1] and .m[2]
	retval;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2();
}

mat2 operator-(const mat2 & A)
{
	return mat2();
}

mat2 operator*(const mat2 & A, float s)
{
	return mat2();
}

mat2 operator*(float s, const mat2 & A)
{
	return mat2();
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	return mat2();
}

mat2 operator*(const mat2 & A, const vec2 & V)
{
	return mat2();
}

float determinant(const mat2 & A)
{
	return 0.0f;
}

mat2 inverse(const mat2 & A)
{
	return mat2();
}
