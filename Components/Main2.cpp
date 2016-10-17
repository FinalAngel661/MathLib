#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"
#include "rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"

void main2()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

	Transform playerTransform(200, 200);
	playerTransform.m_scale = { 24,24 };

	Rigidbody playerRigidbody;

	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.intergrate(playerTransform, deltaTime);

		// Draw the player
		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);
	}
	sfw::termContext();
}