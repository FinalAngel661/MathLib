#pragma once
#include "Transform.h"
#include "Mat3.h"
#include "GameState.h"
#include <cmath>
#include <cstdio>

class Graphics
{
private:
	int background;
	int bounds;
public:
	Transform			transform;
	void init();
	void drawBoundary();
	void drawBackgound(const mat3 &camera);
};