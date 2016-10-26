#pragma once

struct CollisionData1D
{
	bool result() const;
	float penetrationDepth;
	float collisionNormal;
	float MTV() const;
};

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax);