#include "shapes.h"
#include "Vec2.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y,1 }).xy;

	float mX = magnitude(T * vec3{ 0, C.rad,0 });
	float mY = magnitude(T * vec3{ C.rad,0,0 });

	retval.rad = mX > mY ? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}

AABB operator*(const mat3 & T, const AABB & box)
{
	AABB retval = box;

	retval.pos = (T * vec3{ box.pos.x,box.pos.y,1 }).xy;

	retval.he = (T * vec3{ box.he.x,box.he.y,0 }).xy;

	vec2 tP[4];

	tP[0] = T * vec3{box.min().x, box.min().y, 1};
	tP[1] = T * vec3{box.max().x, box.max().y, 1 };
	tP[2] = T * vec3{box.max().x, box.min().y, 1 };
	tP[3] = T * vec3{box.min().x, box.max().y, 1 };

	vec2 minv = tP[0].xy; 
	vec2 maxv = tP[0].xy;

	for (int i = 1; i < 4; ++i)
	{
		minv = min(minv, tP[i].xy);
		maxv = max(maxv, tP[i].xy);
	}

	retval.pos = (minv + maxv) / 2;
	retval.he = maxv - minv;

	return retval;
}

Plane operator*(const mat3 & T, const Plane & P)
{
	return Plane();
}

Ray operator*(const mat3 & T, const Ray & R)
{
	return Ray();
}

Hull operator*(const mat3 & T, const Hull & H)
{
	return Hull();
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

/*
	STUB for AABB Trans

	min : pos - he
	max : pos + he

	pos: (max+ min) /2
	he :(max - min) / 2

*/