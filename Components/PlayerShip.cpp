#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

	shotTimer = 0;

	Playersprite.sprite = sfw::loadTextureMap("./res/player.png");
	Playersprite.dims = { 8,8 };

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState &gs)
{
	shotTimer -= deltaTime;
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);
	/*
	if (sfw::getKey('T'))
	{
		gs.tractor.isAlive = true;

	}
	*/
	if (sfw::getKey(' ') && shotTimer < 0)
	{
		// TODO:
		shotTimer = .25f;
		 gs.spawnBullet(transform.getGlobalPosition(),transform.getGlobalUp() * 100 );
	}
	//rigidbody.addForce(vec2{ 0,-10 });

	rigidbody.intergrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 &camera)
{
	Playersprite.draw(camera, transform);
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	
}