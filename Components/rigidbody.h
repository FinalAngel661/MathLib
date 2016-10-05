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

	float angularAccel;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);

	void addTorque(float torque);

	void intergrate(Transform &trans, float deltaTime); //performs intergration

};