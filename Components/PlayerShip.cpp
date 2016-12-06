#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

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
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	//Playersprite.drawplayersprite(camera, transform);
}