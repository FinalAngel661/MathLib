#include "PlanetaryMotor.h"

void PlanetaryMotor::update(Rigidbody & planetRbody)
{
	//planetRbody.angularVelocity = m_rotationSpeed;
	planetRbody.addTorque(m_rotationSpeed);
}
