#pragma once

class Enemy
{
private:
	char name[64];
	int health1;

public:
	void health(const int);
	void takeDamage(int dmg);
	void drawEnemy();
};