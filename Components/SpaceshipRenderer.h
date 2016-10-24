#pragma once
#include "Transform.h"
#include "Mat3.h"

class SpaceshipRenderer
{

public:
	unsigned color;

	SpaceshipRenderer SpaceshipRenderer;

	void draw(const mat3 &T, const Transform &ship);
};