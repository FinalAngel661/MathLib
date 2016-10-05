#include "SpaceshipController.h"
#include "sfwdraw.h"

SpaceshipController::SpaceshipController(unsigned CTR_LEFT, unsigned CTR_RIGHT, unsigned CTR_UP, unsigned CTR_DOWN)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = ;
	CTR_UP = ;
	CTR_DOWN = ;
	CTR_BREAK = ;
}

void SpaceshipController::update(SpaceshipLocomation & loco)
{
	float hInput = 0.0f; 
	hInput -= sfw::getKey('CTR_LEFT');
	hInput += sfw::getKey('CTR_RIGHT');

	float vInput = 0.0f;
	vInput -= sfw::getKey('CTR_DOWN');
	vInput += sfw::getKey('CTR_UP');

	float bInput = sfw::getKey(CTR_BREAK);

	loco.doTurn(hInput);
	loco.doThrust(vInput);
}
