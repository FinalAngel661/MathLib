#include <cassert>
#include <cstdio>

#include "Test.h"


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

	//quad(1, 0, 0);
	//assert(res.roots == 1);
	//assert(res.roots == 2);
	//assert(res.roots == 0);

	/*assert(quad(1, -2, 0).leftRoot == 0);
	assert(quad(1,-2,0).rightRoot == 2);

	assert(quad(1, 0, 0).leftRoot == quad(1, 0, 0).rightRoot)*/

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