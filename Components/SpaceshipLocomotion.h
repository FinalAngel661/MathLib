#pragma once

#include "rigidbody.h"

class SpaceshipLocomotion
{
	/*SpaceshipLocomotion();*/

	float thrust; //forward movement
	float maxthrust; // max forward movement
	float thrustspeed; // rate of change for our thrust
	float stopAction;

	float BreakPower;
	float turn; // turn
	float maxturn; // max turn
	float turnspeed; // rate of change for our turn

	float speed; //movement speed
	float maxspeed;

public:
	SpaceshipLocomotion();
	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);


};