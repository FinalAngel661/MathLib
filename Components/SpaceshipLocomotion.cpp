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

}


void SpaceshipLocomation::doThrust()
{
	if (sfw::getKey('W')) thrust = 1;
}

void SpaceshipLocomation::doTurn()
{
	if (sfw::getKey('Q')) turn += 1;
	if (sfw::getKey('E')) turn -= 1;
}

void SpaceshipLocomation::update(Rigidbody & rigidbody, float deltaTime)
{
	//apply the value to my rigidbody

	//zero out the thrust values
	thrust = 0.0f;
	turn = 0.0f;
}
