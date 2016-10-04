#pragma once
#include "Vec2.h"
#include "Transform.h"

class Rigidbody
{

public:
	Rigidbody();
	vec2 velocity; // represents the change in position
	float angularVelocity;
	vec2 accel;

	void intergrate(Transform &trans, float deltaTime); //performs intergration

};