#pragma once
#include "Vec2.h"


union mat2
{
	float m[4]; // single dimension array
	float mm[2][2]; //multidimensional array
	vec2 c[2]; // column vectors

};


//tranpose(mat2)
// mat2 + mat2 : matrixd addition
//mat2 - mat2 : matrix subtraction
// -mat2

// mat2 * mat2 : matrix multiplied by matrix
//mat2 * vec2 : matrix by vector
//mat2 * float : matrix by scalar
//float * mat2 : scalar by matrix


// determinant(mat2)
// inverse(mat2)