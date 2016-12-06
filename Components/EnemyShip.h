#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"
#include "Sprite.h"


class EnemyShip
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	//SpaceshipController controller;
	//AIController		controller;
	SpaceshipLocomotion locomotion;
	Sprite AISprite;

	EnemyShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};