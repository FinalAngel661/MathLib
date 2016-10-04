#pragma once

class Player
{
private:
	char name[64];
	int health1;

public:
	void health(const int);
	void takeDamage(int dmg);
	void drawPlayer();
	void accel(int acc);
	void rotate(int rot);
};