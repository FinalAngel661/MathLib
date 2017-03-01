#include "ParticleSpawner.h"

#include "vec2.h"
#include <random>

#include <iostream>

ParticleSpawner::ParticleSpawner()
{
	spawnTimer = spawnInterval;

	transform.m_scale.x = 1.0f;
	transform.m_scale.y = 1.0f;
}

ParticleSpawner::~ParticleSpawner()
{

}

void ParticleSpawner::update(float deltaTime, GameState & gs)
{
	if (!particlePool.isEmpty())
	{
		// update particles
		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter)
		{
			(*iter).update(deltaTime, gs);

			if ((*iter).isExpired())
			{
				std::cout << "Particle freed..." << std::endl;
				iter.free();
			}
		}
	}

	// tick particle timer
	spawnTimer -= deltaTime;
	if (spawnTimer < 0)
	{
		std::cout << "Particle spawned..." << std::endl;

		Particle part;
		part.transform.m_parent = &transform;
		part.lifetime = 5;
		part.transform.m_scale.x = 50;
		part.transform.m_scale.y = 50;

		vec2 rDir;
		rDir.x = 0;
		rDir.y = 1;
		rDir = fromAngle(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2.0f)) - 1.0f);
		part.rigidbody.addForce(rDir * (1000));

		particlePool.push(part);

		// reset spawn timer
		spawnTimer = spawnInterval;
	}
}

void ParticleSpawner::draw(const mat3 & camera)
{
	if (!particlePool.isEmpty())
		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter)
		{
			(*iter).draw(camera);
		}
}