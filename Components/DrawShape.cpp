#include "DrawShape.h"
#include "sfwdraw.h"

void drawCircle(const Circle & C, unsigned color)
{
	sfw::drawCircle(C.pos.x, C.pos.y, C.rad, 12U, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	sfw::drawLine(B.pos.x, B.pos.y, 12U, color);
	sfw::drawLine(B.min().x, B.max().y, B.max().x, B.min().y, color);
	sfw::drawLine(B.max().x, B.min().y, 12U, color);
	sfw::drawLine(B.min().x, B.min().y, 12U, color);
	sfw::drawLine(B.max().x, B.max().y, 12U, color);
	sfw::drawLine(B.pos.x, B.pos.y, B.pos.y, B.pos.x, color);

	//sfw::drawCircle(B.pos.x, B.pos.y, 4U, color);
}
