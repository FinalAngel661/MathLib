#include "EnemyShip.h"
#include "GameState.h"
#include <cmath>
#include <cstdio>

EnemyShip::EnemyShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

	AISprite.sprite = sfw::loadTextureMap("./res/AI.png");
	AISprite.dims = { 5,5 };

	transform.m_scale = vec2{ 10,10 };
}

void EnemyShip::update(float deltaTime, GameState &gs)
{
	// This enemy's position
	vec2 dir = 
		normal(gs.player.transform.m_position - transform.m_position);
	
	transform.getUp(); // direction the ship is facing

	// turn left(1) or right(-1)?

	//gs.player.transform.getDirection;

	//if (gs.player.transform.m_facing = transform.m_facing)
	//{
	//	locomotion.doThrust(1);
	//}
	float diff = fabsf(gs.player.transform.m_facing - transform.m_facing);

	// dot product tells us how much the two vectors overlap
	// -1 and 1-- based on this, we can govern the agent's behavior
	if( dot(perp(dir), transform.getGlobalUp()) > -.9f)
	{
		printf("%f,\n", diff);
		locomotion.doTurn(1);
	}
	else
	{
		locomotion.doThrust(1);
	}

	//locomotion.doThrust(1); // thrust forward
	locomotion.update(transform, rigidbody);
	rigidbody.intergrate(transform, deltaTime);
}

void EnemyShip::draw(const mat3 &camera)
{
	AISprite.draw(camera, transform);
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}