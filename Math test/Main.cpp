#include <cassert>
#include <cstdio>

#include "Test.h"
#include "Vec2.h"
#include "fops.h"
#include "fops.cpp"
#include "Vec3.h"
#include "mat.h"
#include "Mat3.h"

//This is the develop branch
//jfjf

int main()
{
	assert(fequals(0, 0.000001));
	//////////////////////////////////////
	// Vector Tests

	// if the vector only extends in one axis, then it's
	// magnitude will be the extent within that axis!
	assert(fequals(magnitude(vec2{ 5,0 }), 5));

	// magnitude of the normal should be 1
	vec2 N = normal(vec2{ 1,1 });
	assert(fequals(magnitude(N), 1));

	// Dot product with an AXIS should give us the coordinate value
	// along that axis.
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	// Anglebetween the X-Axis should give us the angle of the vector.
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	// Angle of 0 should be the X-Axis
	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));
	assert((fromAngle(deg2rad(45))) == normal(vec2{ 1,1 }));

	//Testing cross product
	//Ensure that the Z-axis results from
	//crossing the X-axis and Y-Axis
	//	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{0,0,1}));

	// reversing the operands will give me the back-facing vector.
	//	assert( (cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }) );

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 0), 124));
	/*assert(fequals(lerp(.23, 124, 0), .5f));*/

	assert(fequals(QuadBezier(15, 40, 21, 0), 1));
	assert(fequals(QuadBezier(15, 40, 21, 1), 2));

	////////////////////////////////////////
//////////////////////Matrix Tests

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 m1 = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	vec2 v0 = vec2{ 1,0 };

	assert(m0 == m0);
	assert(m1 * 2 == 2 * m1);
	assert((m1 * 2 == mat2{ 2,0,0,2 }));
	assert(m1 + m0 == m1);
	assert(m1 - m1 == m0);
	assert(m1 *-1 == -m1);

	assert(m1 * m1 == m1);
	assert((mat2{ 1,2,3,4 }) * m1 == (mat2{ 1,2,3,4 }));

	assert(m1 * v0 == v0);
	assert((t0 * v0 == vec2{ 4,2 }));

	assert(transpose(m1) == m1);
	assert(inverse(m1) == m1);

	assert(t0*inverse(t0) == m1);

	vec2 j = { 2,5 };

	assert ((scale(5, 1) * j == vec3{ 10,5,1 }));
	assert ((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));
	assert ((translate(0, 3)*j == vec3{2,8,1}));

	return 0;
}
