#include "Vec2.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x + rhs.x, lhs.y + rhs.y};

}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	// TODO: insert return statement here
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;

}
