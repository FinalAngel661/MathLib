#include "Asteriod.h"

Asteroid::Asteroid()
{
	vec2 hullVrts[] = { { -1, 0 },{ 0,1 },{ 1,0 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 6,6 };
	rigidbody.drag = 0.0f;
	rigidbody.angulardrag = 0.0f;
	rigidbody.mass = 10;
}

void Asteroid::update(float deltaTime, GameState & gs)
{
	rigidbody.intergrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}