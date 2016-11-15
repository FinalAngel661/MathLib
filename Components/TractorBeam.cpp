#include "TractorBeam.h"

TractorBeam::TractorBeam()
{
	vec2 hullvrts[] = { {.1f,.3f},{-.1f,.3f},{-4.f,6.f},{4.f,6.f} };
	collider = Collider(hullvrts, 4);

	transform.m_scale = vec2{ 100,100 };
	isAlive = false;
	oneFrame = false;
}

void TractorBeam::update(float deltaTime, GameState & gs)
{
	if (oneFrame)
	{
		isAlive = false;
		oneFrame = false;
	}
	if (isAlive)
	{
		oneFrame = true;
	}
}

void TractorBeam::draw(const mat3 & camera)
{
	if (isAlive) return;
}
