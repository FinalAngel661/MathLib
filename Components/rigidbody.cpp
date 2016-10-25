#include "rigidbody.h"
#include "sfwdraw.h"

Rigidbody::Rigidbody()
{
	mass = 1;
	drag = 0.25;
	angulardrag = 1.f;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	accel = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAccel = 0.0f;
	torque = 0;
}

void Rigidbody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void Rigidbody::addImpulse(const vec2 & a_impulse)
{
	impulse += impulse;
}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}

void Rigidbody::intergrate(Transform & trans, float deltaTime)
{
	// Position
	accel = force / mass;
	velocity += accel * deltaTime + impulse / mass;
	trans.m_position += velocity * deltaTime;
	force = impulse = { 0,0 };

	// dampening force
	force = -velocity * drag;

	// Rotation
	angularAccel = torque / mass;
	angularVelocity += angularAccel * deltaTime;
	trans.m_facing += angularVelocity * deltaTime;

	torque = 0;

	torque = -angularVelocity * angulardrag;
}

void Rigidbody::debugDraw(const mat3& T, const Transform & trans)
{
	vec2 p = ( T * trans.getGlobalTransform())[2].xy;
	vec2 v = p + velocity;
	vec2 a = accel + p;

	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}
