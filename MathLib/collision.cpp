#include "collision.h"
#include <cmath>

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pDr = Amax - Bmin;
	float PD1 = Bmax - Amin;

	retval.penetrationDepth = fmin(pDr, PD1);

	retval.collisionNormal = copysignf(1, PD1 - pDr);

	//retval.result = retval.penetrationDepth >= 0;
	//retval.MTV = retval.penetrationDepth * retval.collisionNormal;

	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	//CollisionData1D retval;

	//return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D YCD = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *YCD.collisionNormal;
	}

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}

/* tri = pos + vel * t  */

/* 
Amin + tri.A * t 
Amax + tri.A * t
*/

bool CollisionData::result() const
{
	return false;
}

vec2 CollisionData::MTV() const
{
	return vec2();
}

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}
