#pragma once
#include "Vec2.h"
#include "Transform.h"

class Rigidbody
{

public:
	Rigidbody();

	float mass, drag, angulardrag;

	vec2 force, impulse;
	vec2 velocity; // represents the change in position
	float angularVelocity;
	vec2 accel;

	float torque;
	float angularAccel;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);

	void intergrate(Transform &trans, float deltaTime); //performs intergration


	void debugDraw(const mat3& T, const Transform &trans);
};