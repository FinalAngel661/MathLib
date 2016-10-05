#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"
#include "Player.h"
#include "rigidbody.h"

float W = 400, H = 400;

vec2 player = { 400,400 };
vec2 playerVelocity = { 0,0 };

Transform playerTransform(200, 200);
Rigidbody playerRigidbody;

void Player::health(const int)
{
	health1 = 10;
}

void Player::takeDamage(int dmg)
{
	health1 -= dmg;
}

void Player::drawPlayer()
{
	playerTransform.scale = { 5,5 };

	//Player
	sfw::drawCircle(player.x, player.y, 5.f);
	if (sfw::getKey('W')) playerRigidbody.accel.y += 100.0f;
	if (sfw::getKey('S')) playerRigidbody.accel.y -= 100.0f;
	//if (sfw::getKey('A')) playerRigidbody.accel.x -= 100.0f;
	//if (sfw::getKey('D')) playerRigidbody.accel.x += 100.0f;

	if (sfw::getKey('Q')) playerRigidbody.angularVelocity += 1.0f;
	if (sfw::getKey('E')) playerRigidbody.angularVelocity -= 1.0f;

	//Intergration
	player = player + playerVelocity * sfw::getDeltaTime();

	//Wrap
	if (playerTransform.position.x < W) playerTransform;
	else if (player.x > W) player.x = 0;
	if (player.y < 0) player.y = H;
	else if (player.y > H) player.y = 0;


	

	playerRigidbody.intergrate(playerTransform, 5.f);
	playerTransform.debugDraw();

}
