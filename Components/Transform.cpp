#include "Transform.h"
#include "sfwdraw.h"
#include "Vec2.h"
#include "fops.h"

Transform::Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0) : facing(a), position({ x,y }), scale({w,h}) // member initialization!
{
	//position.x = 0;
	//position.y = 0;

	//scale.x = 28;
	//scale.y = 8;

	//facing = 0;
}

//Transform::Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0) : Transform() // ctor chaining!
//{
//	position.x = x;
//	position.y = y;
//}

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
