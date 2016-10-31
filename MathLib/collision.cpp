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

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max.x, dB.x);

	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max.y, dB.y);

	vec2 axis;
	float handedness;

	if (Yres.entryTime < Xres.entryTime && !isinf(Xres.entryTime))
	{
		axis = vec2{ 1,0 };
		handedness = Xres.collisionNormal;

		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;

	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
	}

	if (Yres.exitTime < Xres.exitTime)
	{
		retval.exitTime = Yres.exitTime;
	}
	else
	{
		retval.exitTime = Xres.exitTime;
	}
	
	return retval;
}

CollisionDataSwept boxCollision(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	CollisionData1D Xdis = sweptDetection1D(A.min().x, A.max().x,B.min().x, B.max().x); 
	CollisionData1D Ydis = sweptDetection1D(A.min().x,A.max().x,B.min().x,B.max.x);

	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max.x, dB.x);

	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max.y, dB.y);

	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);


	if (Yres.entryTime < Xres.entryTime || xSwept && !ySwept)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;

	}
	else if (ySwept)
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
		retval.collides = ySwept || Ydis.result();
	}

	if (Yres.exitTime < Xres.exitTime)
	{
		retval.exitTime = Yres.exitTime;
	}
	else
	{
		retval.exitTime = Xres.exitTime;
	}

	return retval;
}

CollisionData PlaneboxCollision(const Plane & P, const AABB & B)
{
	return CollisionData();
}

CollisionDataSwept planeboxCollisionSwept(const Plane & P, const AABB & B, const vec2 & Bvel)
{
	return CollisionDataSwept();
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
