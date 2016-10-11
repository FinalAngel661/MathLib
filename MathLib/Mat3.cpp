#include "Mat3.h"

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return !(A == B);
}

bool operator==(const mat3 & A, const mat3 & B)
{
	bool retval = true;

	for (int i = 0; i < 3; ++i)
		retval = retval && A[i] == B[i];

	return retval;
	return A[0] == B[0] && A[1] == B[1] && A[2] == B[2];
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	for (int i = 0; i < 3; i++)
		retval[i] = A[i] - B[i];

	return retval;
}

mat3 mat3Identity()
{
	//int a = 0;

	//for (int column = 0; column < 3; ++column)
	//{
	//	for  (int row = 0; row < 3; row++)
	//	{
	//		if (column == a && row == a)
	//		{
	//			mat3Identity.mm[column][row] = 1;
	//			a += 1;
	//		}
	//		else mat3Identity.mm[column][row] = 0;
	//	}
	//}

	return mat3{1,0,0,0,1,0,0,0,1};
}

mat3 transpose(const mat3 & A)
{
	mat3 retval;

	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			retval[i][j] = A[j][i];

	return retval;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	A + -B;


}

mat3 operator-(const mat3 & A)
{
	return A*-1;
}

mat3 operator*(const mat3 & A, float s)
{
	mat3 retval;

	//for(int i = 0)

}

mat3 operator*(float s, const mat3 & A)
{
	return mat3();
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	retval.m[0] = A.m[0] * B.m[0] + A.m[3] * B.m[1] + A.m[6] * B.m[2];
	retval.m[1] = A.m[1] * B.m[0] + A.m[4] * B.m[1] + A.m[7] * B.m[2];
	retval.m[2] = A.m[2] * B.m[0] + A.m[5] * B.m[1] + A.m[8] * B.m[2];

	retval.m[0] = A.m[0] * B.m[3] + A.m[3] * B.m[4] + A.m[6] * B.m[5];
	retval.m[1] = A.m[1] * B.m[3] + A.m[4] * B.m[4] + A.m[7] * B.m[5];
	retval.m[2] = A.m[2] * B.m[3] + A.m[5] * B.m[4] + A.m[8] * B.m[5];

	retval.m[0] = A.m[0] * B.m[6] + A.m[3] * B.m[7] + A.m[6] * B.m[8];
	retval.m[1] = A.m[1] * B.m[6] + A.m[4] * B.m[7] + A.m[7] * B.m[8];
	retval.m[2] = A.m[2] * B.m[6] + A.m[5] * B.m[7] + A.m[8] * B.m[8];

	mat3 At = transpose(A);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			retval[i][j] = dot(At[j], B[i]);

	return retval;
}

mat3 operator*(const mat3 & A, const vec3 & V)
{
	return mat3();
}

float determinant(const mat3 & A)
{
	return 0.0f;
}

mat3 inverse(const mat3 & A)
{
	return mat3();
}
