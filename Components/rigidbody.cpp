#include "rigidbody.h"

Rigidbody::Rigidbody()
{
	mass = 1;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	accel = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAccel = 0.0f;
}

void Rigidbody::addForce(const vec2 & force)
{
	accel += force;
}

void Rigidbody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
	//angularAccel += torque;
}

void Rigidbody::intergrate(Transform & trans, float deltaTime)
{
	accel = force / mass;
	velocity += accel * deltaTime + impulse / mass;
	/*velocity += accel * deltaTime;*/
	angularVelocity += angularAccel * deltaTime;
	force = impulse = { 0,0 };

	angularAccel = torque / mass;
	//perform euler intergration
	//trans.position = trans.position + velocity * deltaTime;
	trans.facing += angularVelocity * deltaTime;
	torque = 0;
}
