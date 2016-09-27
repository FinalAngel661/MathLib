#include "Vec2.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}
// -
vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}
//*
vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}
vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ lhs.x *rhs, lhs.y * rhs };
}
vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}
vec2 operator/(float rhs, const vec2 & lhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}
vec2 operator-(const vec2 & v)
{
	return vec2();
}
vec2 operator+(const vec2 & v)
{
	return vec2();
}
bool operator==(const vec2 &lhs, const vec2&rhs)
{

	return lhs.x == rhs.x && lhs.y == rhs.y;

}
