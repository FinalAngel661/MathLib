#include "Sprite.h"

#include "sfwdraw.h"

void Sprite::draw(const mat3 & camera, const Transform & transform)
{
	mat3 drawMat = camera * transform.getGlobalTransform() * scale(dims);

	sfw::drawTextureMatrix3(sprite, 0, WHITE, drawMat.m);
}