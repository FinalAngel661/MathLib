#include <cassert>
#include <cstdio>

#include "Test.h"
#include "Vec2.h"
#include "fops.h"
#include "fops.cpp"
#include "Vec3.h"

//This is the develop branch
//jfjf

int main()
{

	//Unit Tests
	assert(donothing(0) == 5);
	assert(donothing(-1) == 4);
	assert(donothing(1) == 8);

	assert(quadfunc(0) == -7);
	assert(quadfunc(-1) == -8);
	assert(quadfunc(1) ==  -4);

	//Vector tests
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2));

	vec2 var = { 4,0 };
	var += vec2{ -3,1 };
	assert((var == vec2{ 1,1 }));

	vec2 N = normal(vec2{ 1,1 });
	assert(N.x == N.y);

	assert(magnitude(N) == 1);
	assert(normal(N) == N);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));

	assert(fequals(1, .9999999f));

	


	vec2 N = normal(vec2{ 1,1 });
	assert(fequals(magnitude(N), 1));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));

	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }), deg2rad(45)));


	assert(fequasls(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), facing(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));
	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,-1 }));

	return 0;

	//quad(1, 0, 0);
	//assert(res.roots == 1);
	//assert(res.roots == 2);
	//assert(res.roots == 0);

	/*assert(quad(1, -2, 0).leftRoot == 0);
	assert(quad(1,-2,0).rightRoot == 2);

	assert(quad(1, 0, 0).leftRoot == quad(1, 0, 0).rightRoot);*/

	float lerp(float start, float end, float t)
	{
		return start + t * (end - start);
	}

//	distance formaula:
	float distance(float x1, float y1, float x2, float y2)
	{
		return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}

	getchar();
	return 0;
}

