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

void drawPlane(const Plane & P, unsigned color)
{
	sfw::drawCircle(P.pos.x, P.pos.y, 12, 12, color);

	sfw::drawLine(P.pos.x, P.pos.y, P.dir.x, P.dir.y, color);

	vec2 left = perp(P.dir);
	vec2 right = -perp(P.dir);
	sfw::drawLine(P.pos.x, P.pos.y, P.pos.x +left.x*80, P.pos.y +left.y*80, color);
	sfw::drawLine(P.pos.x, P.pos.y, P.pos.x + right.x * 80, P.pos.y + right.y * 80, color);
}
