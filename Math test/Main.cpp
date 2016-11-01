#include <cassert>
#include <cstdio>

#include "shapes.h"
#include "Test.h"

#include "Vec2.h"
#include "Vec3.h"
#include "Mat4.h"
#include "collision.h"

//This is the develop branch
//jfjf

int main()
{

	//Unit Tests
	//assert(donothing(0) == 5);
	//assert(donothing(-1) == 4);
	//assert(donothing(1) == 8);

	//assert(quadfunc(0) == -7);
	//assert(quadfunc(-1) == -8);
	//assert(quadfunc(1) ==  -4);

	//quad(1, 0, 0);
	//assert(res.roots == 1);
	//assert(res.roots == 2);
	//assert(res.roots == 0);

	/*assert(quad(1, -2, 0).leftRoot == 0);
	assert(quad(1,-2,0).rightRoot == 2);

	assert(quad(1, 0, 0).leftRoot == quad(1, 0, 0).rightRoot)*/

//	float lerp(float start, float end, float t)
//	{
//		return start + t * (end - start);
//	}
//
////	distance formaula:
//	float distance(float x1, float y1, float x2, float y2)
//	{
//		return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
//	}

	// vec2
	// equality
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 0,0 } != vec2{ 0,1 }));

	// vec3
	// equality
	assert((vec3{ 0,0,0 } == vec3{ 0,0,0 }));
	assert((vec3{ 0,0,0 } != vec3{ 0,0,1 }));

	// matrix3
	// equality
	assert((mat3{ 0,0,0,0,0,0,0,0,0 } == mat3{ 0,0,0,0,0,0,0,0,0 }));
	assert((mat3{ 0,0,0,0,0,0,0,0,0 } != mat3{ 0,0,0,0,0,0,0,0,1 }));

	//assert(translate({0,0} == )

	assert(fequals(lerp(0, 1, 1), 1));

	int things[5];
	things[0];

	Circle c = {0, 0, 5};

	assert((translate({ 4, 0 }) * c == Circle{ 4,0,5 }));

	assert((scale({2, 1}) * c == Circle{ 4,0,10 }));
	assert((scale({ 2, 2 }) * c == Circle{ 4,0,10 }));
	assert((scale({ 1, 2 }) * c == Circle{ 4,0,10 }));

	assert((scale({ -1, 1 }) * c == Circle{ 4,0,5 }));

	assert((rotate(45) * c == Circle{ 0,0,5 }));

	AABB As = { 0,0,1,1 };
	AABB Bs = { 10,0,1,1 };

	assert(fequals(boxCollisionSwept(As, vec2{ 1,0 }, Bs, vec2{ -1,0 }).entryTime, 4));

	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).entryTime, -4));

	AABB Bp = { 0,0,4,4 };

	Plane P1 = { 0,0,0,1 };
	Plane P2 = { 0,-10,0,1 };
	Plane P3 = {0,10,0,1};
	Plane P4 = {vec2{6,6}, normal(vec2{-1,1})};
	Plane P5 = { vec2{6,6}, normal(vec2{-1,-1})};

	assert(PlaneboxCollision(P1, Bp).result());
	assert(!PlaneboxCollision(P2, Bp).result());
	assert(PlaneboxCollision(P3, Bp).result());
	assert(PlaneboxCollision(P4, Bp).result());
	assert(!PlaneboxCollision(P5, Bp).result());

	assert(fequals(planeboxCollisionSwept(P3, Bp, vec2{ 1,0 }).entryTime, 2.5f));

	//assert(collisiondetection);
	

	//getchar();
	return 0;
}