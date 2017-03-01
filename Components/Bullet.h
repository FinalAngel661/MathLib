#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Sprite.h"

class Bullet
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	Sprite				Bsprite;
	float				lifespan; // how long it lives
	bool				toDelete;

	Bullet();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};
