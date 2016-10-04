#include "rigidbody.h"

Rigidbody::Rigidbody()
{
	accel = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
}

void Rigidbody::intergrate(Transform & trans, float deltaTime)
{
	velocity += accel * deltaTime;

	//perform euler intergration
	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}
