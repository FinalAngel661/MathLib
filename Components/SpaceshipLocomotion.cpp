#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

SpaceshipLocomation::SpaceshipLocomation()
{
	thrust = 0.0f;
	maxthrust = 100.0f;
	thrustspeed = 1.0f;

	turn = 0.0f;
	maxturn = 100.0f;
	turnspeed = 1.0f;

	speed = 500.0f;
	maxspeed = 1000.0f;

}


void SpaceshipLocomation::doThrust(float value)
{
	thrust = value;
}

void SpaceshipLocomation::doTurn(float value)
{
	turn = value;
}

void SpaceshipLocomation::update(Rigidbody & rigidbody, float deltaTime)
{
	//apply the value to my rigidbody
	rigidbody.accel.x = thrust * speed * deltaTime;
	rigidbody.accel.y = turn * speed * deltaTime;

	if (magnitude(rigidbody.velocity) > maxspeed)
	{
		vec2 dir = normal(rigidbody.velocity);

		rigidbody.velocity = dir * maxspeed;

	}


	//zero out the thrust values
	thrust = 0.0f;
	turn = 0.0f;
}
