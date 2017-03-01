#include "Asteriod.h"
#include "sfwdraw.h"

Asteroid::Asteroid()
{
	vec2 hullVrts[] = { { -3, 0 },{ 0,3 },{ 3,0 } };
	collider = Collider(hullVrts, 3);

	asterSprite.sprite = sfw::loadTextureMap("./res/Asteroid.png");
	asterSprite.dims = { 5,5 };

	transform.m_scale = vec2{ 15,15 };
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
	asterSprite.draw(camera, transform);
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);

}