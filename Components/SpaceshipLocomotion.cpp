#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	thrust = 0.0f;
	maxthrust = 100.0f;
	thrustspeed = 1.0f;

	turn = 0.0f;
	maxturn = 100.0f;
	turnspeed = 1.0f;
	BreakPower = 4.0f;

	speed = 500.0f;
	maxspeed = 1000.0f;

}


void SpaceshipLocomotion::doThrust(float value)
{
	thrust = value;
}

void SpaceshipLocomotion::doTurn(float value)
{
	turn = value;
}

void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::update(const Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getDirection() * speed * thrust);
	rigidbody.addTorque(turnspeed * turn);

	/*thrust = 0;
	turn = 0;
	stopAction = 0;*/

	//apply the value to my rigidbody
	rigidbody.accel.x = thrust * speed;
	rigidbody.accel.y = turn * speed;

	float currentSpeed = magnitude(rigidbody.velocity);

	rigidbody.addForce(-rigidbody.velocity);
	rigidbody.addTorque(-rigidbody.angularVelocity * BreakPower * stopAction);

	/*if (magnitude(rigidbody.velocity) > maxspeed)
	{
		vec2 dir = normal(rigidbody.velocity * BreakPower * stopAction);

		rigidbody.velocity = dir * maxspeed;

	}
*/

	//zero out the thrust values
	thrust = 0.0f;
	turn = 0.0f;
	stopAction = 0.0f;
}
