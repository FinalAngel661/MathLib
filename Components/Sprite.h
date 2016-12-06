#pragma once
#include "Mat3.h"

class Sprite
{
public:
	int sprite;

	void init();
	void drawplayersprite(const mat3 &camera);
};