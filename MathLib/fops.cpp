#include "fops.h"
#include <cmath>
#include <cfloat>

bool fequels(float lhs, float rhs)
{
	fabsf(lhs - rhs) <= 0.000001f;

	FLT_EPSILON;
	0.0000001f;

	return false;
}
