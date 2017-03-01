#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"
#include "Sprite.h"


class PlayerShip
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;
	Sprite				Playersprite;

	float shotTimer;

	PlayerShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};