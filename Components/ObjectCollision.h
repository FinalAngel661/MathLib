#pragma once

#include "Asteriod.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "TractorBeam.h"
#include "Bullet.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void EnemyAstroidCollision(EnemyShip &enemy, Asteroid &as);

void EnemyPlayerCollision(EnemyShip &enemy, PlayerShip &player);

//void TracAsteroidCollision(TractorBeam &TracBeam, Asteroid &as);

void BulletAsteroidCollision(Bullet &bullet, Asteroid &asteroid);