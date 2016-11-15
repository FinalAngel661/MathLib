#pragma once


class GameState
{

public:
	PlayerShip player;

	void play();
	void update(float deltaTime);
	void draw();
};