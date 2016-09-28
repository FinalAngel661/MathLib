#include "Transform.h"
#include "sfwdraw.h"
#include "Vec2.h"
#include "fops.h"

Transform::Transform() : facing(0), position({ 0,0 }), scale({28,8}) // member initialization!
{
	position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 8;

	facing = 0;
}

Transform::Transform(float x, float y) : Transform() // ctor chaining!
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 12);

	vec2 dirEnd = position + getDirection() * 12;
	vec2 upEnd = position + perp(getDirection()) * 12;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, GREEN);

}
