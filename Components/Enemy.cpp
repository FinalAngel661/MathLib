#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"
#include "Enemy.h"
#include "rigidbody.h"

float W1 = 400, H1 = 400;

vec2 enemy = { 400,400 };
vec2 EnemyVelocity = { 0,0 };

Transform EnemyTransform(200, 200);
Rigidbody EnemyRigidbody;

void Enemy::health(const int)
{
	health1 = 10;
}

void Enemy::takeDamage(int dmg)
{
	health1 -= dmg;
}

void Enemy::drawEnemy()
{
	EnemyTransform.m_scale = { 5,5 };

	//vec2 FindVec(enemy.m_position.x - player.m_position.x, enemy.m_position.y - player.m_position.y);

	////Player
	//sfw::drawCircle(enemy.x, enemy.y, 5.f);
	//if (sfw::getKey('W')) EnemyRigidbody.accel.y += 100.0f;
	//if (sfw::getKey('S')) EnemyRigidbody.accel.y -= 100.0f;
	////if (sfw::getKey('A')) playerRigidbody.accel.x -= 100.0f;
	////if (sfw::getKey('D')) playerRigidbody.accel.x += 100.0f;

	//if (sfw::getKey('Q')) EnemyRigidbody.angularVelocity += 1.0f;
	//if (sfw::getKey('E')) EnemyRigidbody.angularVelocity -= 1.0f;

	//Intergration
	enemy = enemy + EnemyVelocity * sfw::getDeltaTime();

	//Wrap
	if (EnemyTransform.m_position.x < W1) EnemyTransform;
	else if (enemy.x > W1) enemy.x = 0;
	if (enemy.y < 0) enemy.y = H1;
	else if (enemy.y > H1) enemy.y = 0;




	EnemyRigidbody.intergrate(EnemyTransform, 5.f);
	EnemyTransform.debugDraw();

}
