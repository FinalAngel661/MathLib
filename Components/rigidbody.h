#pragma once
#include "Vec2.h"
#include "Transform.h"

class Rigidbody
{

public:
	vec2 velocity; // represents the change in position

	void intergrate(Transform &trans, float deltaTime); //performs intergration

};