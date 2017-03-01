#pragma once

#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Camera.h"
#include "Asteriod.h"
#include "GravBullet.h"
#include "TractorBeam.h"
#include "MainMenu.h"
#include "Quit.h"
#include "Splash.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "SpaceshipRenderer.h"
#include "Graphics.h"
#include "Bullet.h"
#include "ObjectPool.h"

//using base::ObjectPool;
//using namespace base;

class AstoriodScore
{
public:
	void init();
	int p1Score = 0;
	int p2Score = 0;
	int AIScore = 0;
	float timer;
	int init2 = 1;
};

class GameState
{

public:
	EnemyShip enemy;
	PlayerShip player;
	Camera camera;
	AstoriodScore asteroidScore;
	//GravBullet bullet;
	//TractorBeam tractor;
	Main Menu;
	Quit quit;
	Splash splash;
	Graphics Gr;
	base::ObjectPool<Bullet> bullets;
	base::ObjectPool<Asteroid> asteroids;

	int font;
	char ans;

	//Time and Score
	float x;
	float y;
	float x2;
	float y2;
	float counter;
	float size;
	float timer;

	GameState() : bullets(128) {}
	GameState() : asteroids(5) {}

	void init(int a_font);
	void play();				  
	void update(float deltaTime); // equivalent of step
	void draw();

	void spawnBullet(vec2 pos, vec2 vel);
	void spawnAsteriod(vec2 pos, vec2 vel);

	bool isGameOver() const;
	APP_STATE next();
};

