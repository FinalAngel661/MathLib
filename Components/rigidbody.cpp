#include "rigidbody.h"

Rigidbody::Rigidbody()
{
	accel = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
}

void Rigidbody::addForce(const vec2 & force)
{
	accel += force;
}

void Rigidbody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}

void Rigidbody::addTorque(float torque)
{
	angularAccel += torque;
}

void Rigidbody::intergrate(Transform & trans, float deltaTime)
{
	velocity += accel * deltaTime;

	//perform euler intergration
	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}
