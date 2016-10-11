#include "mat.h"
#include "fops.h"

vec2 mat2::operator[](unsigned idx) const
{
	return vec2();
}

vec2 & mat2::operator[](unsigned idx)
{
	return m[idx];
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return !(A == B);
}

bool operator==(const mat2 & A, const mat2 & B)
{
	return fequals(A.m[0], B.m[0]) && 
		fequals(A.m[1], B.m[1]) && 
		fequals(A.m[2], B.m[2]) && 
		fequals(A.m[3], B.m[3]);

	//return A[0] == B[0] && A[1] == B[1];
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	/*
	for(int row = 0; row < 2; ++row)
	{
	for(int column = 0; column < 2; ++column)
	{
	mm[column][row] = 0;
	}
	}
	*/

	return mat2{ A.m[0] + B.m[0],
		A.m[1] + B.m[1],
		A.m[2] + B.m[2],
		A.m[3] + B.m[3] };

	// mat2 retval;
	// retval[0] = A[0] + B[0];
	// retval[1] = A[1] + B[1];
	//return retval;
}

mat2 mat2Identity()
{
	return {1,0,0,1};
}

mat2 transpose(const mat2 &A)
{
	
		for(int column = 0; column < 2; ++column)
		{
			for(int row = 0; row < 2; ++row) A.mm[column][row] 
			= mm[row][column];
		}

		for(int column = 0; column < 2; ++ column)
		{
			for(int row = 0; row < 2; ++row) mm[column][row] 
			= A.mm[column][row];
		}
	
	


	//// copy the diagnal
	//mat2 retval = A;

	////what values here need to change?
	//// .m[1] and .m[2]
	//retval;

	//retval.mm[1][0] = A.mm[0][1];
	//retval.mm[0][1] = A.mm[1][0];

	//return A;
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	
		for(int row = 0; row < 2; --row)
		{
			for(int column = 0; column < 2; --column)
			{
				A.mm[column][row] = 0;
			}
		}
	


	 mat2 retval;
	 retval[0] = A[0] - B[0];
	 retval[1] = A[1] - B[1];
	return retval;
}

mat2 operator-(const mat2 & A)
{
	return A*-1;
}

mat2 operator*(const mat2 & A, float s)
{
	
	for(int column = 0; column < 2; ++column)
	{
		for(int row = 0; row < 2; ++row)
		{
			for(int inner = 0; inner < 2; ++inner)
			{
				temp.mm[column][row] += A.mm[column][inner] * s.mm[inner][row];
			}
		}
	}
	

	// mat2 retval;
	// retval[0] = A[0] * s;
	// retval[1] = A[1] *s;
	//return retval;
}

mat2 operator*(float s, const mat2 & A)
{
	return mat2();
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	for (int column = 0; column < 2; ++column)
	{
		for (int row = 0; row < 2; ++row)
		{
			for (int inner = 0; inner < 2; ++inner)
			{
				temp.mm[column][row] += A.mm[column][inner] * B.mm[inner][row];
			}
		}
	}



	/*mat2 At = transpose(A);
	mat2 retval;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			retval[j][i] = dot(At[i], B[j]);

	return retval;*/
}

mat2 operator*(const mat2 & A, const vec2 & V)
{
	mat2 At = transpose(A);
	vec2 retval;

	retval[0] = dot(At[0], V);
	retval[1] = dot(At[1], V);

	return retval;
}

float determinant(const mat2 & A)
{
	return 0.0f;
}

mat2 inverse(const mat2 & A)
{
	return mat2();
}
