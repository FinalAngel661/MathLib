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
	//Player
	sfw::drawCircle(player.x, player.y, 5.f);
	if (sfw::getKey('W')) playerVelocity.y += 100.0f;
	if (sfw::getKey('S')) playerVelocity.y -= 100.0f;
	if (sfw::getKey('A')) playerVelocity.x -= 100.0f;
	if (sfw::getKey('D')) playerVelocity.x += 100.0f;

	//Intergration
	player = player + playerVelocity * sfw::getDeltaTime();

	//Wrap
	if (player.x < 0) player.x = W;
	else if (player.x > W) player.x = 0;
	if (player.y < 0) player.y = H;
	else if (player.y > H) player.y = 0;

	playerRigidbody.intergrate(playerTransform, 5.f);
	playerTransform.debugDraw();

}

void Player::accel(int acc)
{
	playerRigidbody.velocity = vec2{ 0,0 };
}

void Player::rotate(int rot)
{
}
