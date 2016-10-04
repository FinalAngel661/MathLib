#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

//using namespace sfw;
//using sfw::getKey;

SpaceshipLocomation::SpaceshipLocomation()
{
	thrust = 0.0f;
	maxthrust = 100.0f;
	thrustspeed = 1.0f;

	turn = 0.0f;
	maxturn = 100.0f;
	turnspeed = 1.0f;

	speed = 10.0f;
	maxspeed = 100.0f;

}


void SpaceshipLocomation::doThrust()
{
	if (sfw::getKey('W')) thrust = 1;
}

void SpaceshipLocomation::doTurn()
{
	if (sfw::getKey('A')) turn += 1;
	if (sfw::getKey('D')) turn -= 1;
}

void SpaceshipLocomation::update(Rigidbody & rigidbody, float deltaTime)
{
	//poll for input
	doThrust();
	doTurn();

	//apply the value to my rigidbody
	rigidbody.accel.x = thrust * speed * deltaTime;
	rigidbody.accel.y = turn * speed * deltaTime;

	if (magnitude(rigidbody.velocity) > maxspeed)
	{
		vec2 dir = normal(rigidbody.velocity);

	}


	//zero out the thrust values
	thrust = 0.0f;
	turn = 0.0f;
}
