#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

	Playersprite.sprite = sfw::loadTextureMap("./res/player.png");
	Playersprite.dims = { 10,10 };

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);

	if (sfw::getKey('T'))
	{
		gs.tractor.isAlive = true;

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