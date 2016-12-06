#pragma once

#include "Transform.h"
#include "Mat3.h"

class Sprite
{
public:
	int sprite;
	vec2 dims;

	void draw(const mat3 &camera, const Transform & transform);
};