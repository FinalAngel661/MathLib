#include "GameState.h"
#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "ObjectCollision.h"
#include "constd.h"
#include "TimeScore.h"
#include <time.h>
#include "PlayerShip.h"
#include <random>

void GameState::init(int a_font)
{
	//Time and Score
	x = 100;
	y = 100;
	x2 = 500;
	y2 = 100;
	counter = 0;
	size = 400;
	timer = 300.0f;
	font = a_font;

	Gr.init();
	asteroidScore.init();
}

void AstoriodScore::init()
{
	if (init2 > 0)
	{
		int plScore = 0;
		int p2Score = 0;
		int AIScore = 0;
		int init2 = 0;
	}

}

void Graphics::init()
{
	background = sfw::loadTextureMap("./res/Space.png");
}

void Graphics::drawBackgound(const mat3 &camera)
{
	mat3 drawMat = camera * scale({ 1500.0f,1500.0f });

	sfw::drawTextureMatrix3(background, 0, WHITE, drawMat.m);

	//sfw::drawTexture(background,400,300,sfw::getTextureWidth(background),
	//	sfw::getTextureHeight(background), 0, true);
}

/////////////////////////////
/// Used to setup/reset values to start the game.
void GameState::play()
{
	player.transform.m_position = vec2{ 200,-400 };
	player.transform.m_facing = 0;

	enemy.transform.m_position = vec2{ 200,400 };
	enemy.transform.m_facing = -1;

	/*
	asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);
	*/
}

/////////////////////////////////
// Update, do collision, and any top-level stuff.
// Collision functions would get called here!
void GameState::update(float deltaTime)
{
	enemy.update(deltaTime, *this);
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);

	//return;

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		it->update(deltaTime, *this);
		if (it->toDelete)
		{
			it->toDelete = false;
			it.free();
		}
		else it++;
	}

	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		it->update(deltaTime, *this);
		if (it->toDelete)
		{
			it->toDelete = false;
			it.free();
		}
		else it++;
		
	}
	/*
	for (int i = 0; i < 2; ++i)
		asteroid[i].update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);

	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);
*/
	for (auto it = bullets.begin(); it != bullets.end();++it)
		for (int i = 0; i < 2; ++i)
	{
		BulletAsteroidCollision(*it, asteroids);
	}

	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
		for (int i = 0; i < 2; ++i)
		{
			PlayerAsteroidCollision(player, asteroids);
		}

	for (auto it = asteroids.begin(); it != asteroids.end(); ++it)
		for (int i = 0; i < 2; ++i)
		{
			AsteroidCollision(asteroids, asteroids);
		}
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	Gr.drawBackgound(cam);
	player.draw(cam);
	enemy.draw(cam);
	char score[64];
	sprintf_s(score, 64, "Player 1 Score: %d", asteroidScore.p1Score);
	sfw::drawString(font, score, 100, 200, 20, 20);
	/*sprintf_s(score, 64, "Player 2 Score: %d", astoriods.p2Score);
	sfw::drawString(font, score, 100, 50, 20, 20);*/
	sprintf_s(score, 64, "AI Score: %d", asteroidScore.AIScore);
	sfw::drawString(font, score, 100, 50, 20, 20);

	for (auto it = bullets.begin(); it != bullets.end(); it++)
		it->draw(cam);

	for (auto it = asteroids.begin(); it != asteroids.end(); it++)
		it->draw(cam);
}

bool GameState::isGameOver() const
{
	return false;
}


APP_STATE GameState::next()
{
	char ans; 
	char ans1[64] = "You defeated the enemy! Would you like to play again? (Y/N): ";
	if (timer <= 0)
	{
		sfw::drawString(font, ans1, 100, 300, 16, 16, 0);
		if (sfw::getKey('Y'))
		{
			return ENTERGAME;
		}
		else if (sfw::getKey('N'))
		{	
			return ENTERQUIT;
		}
	}
	return GAME;

}


void GameState::spawnBullet(vec2 pos, vec2 vel)
{
	Bullet b;

	b.transform.m_position = pos;
	b.rigidbody.velocity = vel;

	b.toDelete = false;
	b.lifespan = 5.0f;

	bullets.push(b);
}

void GameState::spawnAsteriod(vec2 pos, vec2 vel)
{
	Asteroid a;

	//random position();

	a.transform.m_position = pos;
	a.rigidbody.velocity = vel;

	a.toDelete = false;
	
	asteroids.push(a);
}
