#include "Vec2.h"
#include "fops.h"
#include "fops.cpp"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}
vec2 operator*(float lhs, const vec2 & rhs)
{
	return vec2{ lhs * rhs.x, lhs * rhs.y };
}

vec2 operator-(const vec2 & v)
{
	return v*-1;
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(vec2 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}


bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !fequals(lhs.x, rhs.x) || !fequals(lhs.y, rhs.y);
}

float magnitude(const vec2 & v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

vec2 normal(const vec2 & v)
{
	return v / magnitude(v);
}

float dot(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y;
}

float angleBetween(const vec2 & lhs, const vec2 & rhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec2 perp(const vec2 & v)
{
	return{ v.y,-v.x };
}

float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);

	return retval;
}

vec2 QuadBezier(const vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	vec2 retval;
	retval.x = QuadBezier(start.x, mid.x, end.x, alpha);
	retval.y = QuadBezier(start.y, mid.y, end.y, alpha);
	return retval;
}

vec2 hermitSpline(const vec2 start, const vec2 s_tan, const vec2 end, const vec2 e_tan, float alpha)
{
	return vec2();
}

vec2 cardinalSpline(const vec2 start, const vec2 mid, const vec2 end, const vec2 tightness, float alpha)
{
	return vec2();
}

vec2 catRomPline(const vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	return vec2();
}
