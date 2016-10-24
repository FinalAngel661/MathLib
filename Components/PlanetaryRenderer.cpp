#include "PlanetaryRenderer.h"

#include "sfwdraw.h"


PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(const mat3& T, Transform & planetTrans)
{
	//mat3 glob = t * planetTrans.getGlobalTransform();

	mat3 glob = T * planetTrans.getGlobalTransform();

	vec2 pos = glob[2].xy;

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);

	//T * < 0, radius, playerTransform();
	float xRad = magnitude(glob * vec3{ size,0,0 });
	float yRad = magnitude(glob * vec3{0, size, 0});

	float rad = xRad > yRad? xRad : yRad;
}