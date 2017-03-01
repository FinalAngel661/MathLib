#include "ObjectCollision.h"


void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		player.transform.m_scale *= .9f;
	}
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void EnemyAstroidCollision(EnemyShip & enemy, Asteroid & as)
{

	CollisionData result =
		DynamicResolution(enemy.transform, enemy.rigidbody, enemy.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		enemy.transform.m_scale *= .9f;
	}
}

void EnemyPlayerCollision(EnemyShip & enemy, PlayerShip & player)
{
	CollisionData result =
		DynamicResolution(enemy.transform, enemy.rigidbody, enemy.collider,
			player.transform, player.rigidbody, player.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		enemy.transform.m_scale *= .9f;
	}
}

void BulletAsteroidCollision(Bullet & bullet, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(bullet.transform, bullet.rigidbody, bullet.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		bullet.toDelete = true;
		//as.destroy:
	}
}

//void TracAsteroidCollision(TractorBeam & TracBeam, Asteroid & as)
//{
//	CollisionData result =
//		DynamicResolution(TracBeam.transform, TracBeam.rigidbody, TracBeam.collider,
//			as.transform, as.rigidbody, as.collider);
//
//	if (result.penetrationDepth >= 0)
//	{
//		// Some sort of negative feedback for colliding
//		as.transform.m_scale *= .9f;
//	}
//}

