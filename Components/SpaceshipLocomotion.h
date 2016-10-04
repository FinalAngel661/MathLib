#pragma once

#include "rigidbody.h"

class SpaceshipLocomation
{
	/*SpaceshipLocomation();*/

	float thrust; //forward movement
	float maxthrust; // max forward movement
	float thrustspeed; // rate of change for our thrust

	float turn; // turn
	float maxturn; // max turn
	float turnspeed; // rate of change for our turn

	float speed; //movement speed

public:
	SpaceshipLocomation();
	void doThrust();
	void doTurn();

	void update(Rigidbody &rigidbody, float deltaTime);


};