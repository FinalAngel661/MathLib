#include "Vec2.h"
#include "fops.h"
#include "fops.cpp"

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
float dot(const vec2 & rhs, const vec2 & lhs)
{
	return 0.0f;
}
float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return 0.0f;
}
vec2 perp(const vec2 & v)
{
	return vec2();
}
vec2 angle(const vec2 & v)
{
	return vec2();
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
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
	return lhs.x == rhs.x && lhs.y == rhs.y;

}

bool operator !=(const vec2 &lhs, const vec2 &rhs);

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return false;
}
