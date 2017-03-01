#include "Bullet.h"
#include "sfwdraw.h"

Bullet::Bullet()
{
	vec2 hullVrts[] = { { -1, 0 },{ 0,1 },{ 1,0 } };
	collider = Collider(hullVrts, 3);

	Bsprite.sprite = sfw::loadTextureMap("./res/Bullet.png");
	Bsprite.dims = { 5,5 };

	transform.m_scale = vec2{ 5,5 };
	rigidbody.drag = 0.0f;
	rigidbody.angulardrag = 0.0f;
	rigidbody.mass = 5;

	float lifespan = 5.0f;
}

void Bullet::update(float deltaTime, GameState & gs)
{
	lifespan -= deltaTime;
	if (lifespan < 0)
		toDelete = true;
	rigidbody.intergrate(transform, deltaTime);
}

void Bullet::draw(const mat3 & camera)
{
	Bsprite.draw(camera, transform);
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
