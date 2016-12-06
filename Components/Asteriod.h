#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Sprite.h"

class Asteroid
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	Sprite		asterSprite;

	Asteroid();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};