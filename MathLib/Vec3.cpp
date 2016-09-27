#include "Vec3.h"

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y };
}
// -
vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y };
}
//*
vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs };
}
vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x *rhs, lhs.y * rhs };
}
vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs };
}
vec3 operator/(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs };
}
vec3 operator-(const vec3 & v)
{
	return vec3();
}
vec3 operator+(const vec3 & v)
{
	return vec3();
}
bool operator==(const vec3 &lhs, const vec3&rhs)
{

	return lhs.x == rhs.x && lhs.y == rhs.y;

}

bool operator !=(const vec3 &lhs, const vec3 &rhs);
