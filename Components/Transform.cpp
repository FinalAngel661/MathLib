#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y,
	float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
}

vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(vec2{ m_scale.x , m_scale.y });
	mat3 T = translate(vec2{ m_position.x, m_position.y });
	mat3 R = rotate(m_facing);

	mat3 RES = { 0,-1,0,2,0,0,4,3,1 };

	//bool S*T*R == RES;
	//bool S*R*T == RES;
	bool test = T*S*R == RES;
	//bool T*R*S == RES;
	//bool R*S*T == RES;
	//bool R*T*S == RES;

	return T*S*R;
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getLocalTransform();

	vec3 pos = L[2];

	vec3 right = L*vec3{ 1,0,0 };
	vec3 up = L*vec3{ 0,1,0 };

	sfw::drawLine(m_position.x, m_position.y,
		right.x, right.y, RED);

	sfw::drawLine(m_position.x, m_position.y,
		up.x, up.y, GREEN);

	sfw::drawCircle(m_position.x,
		m_position.y, 12, 12, 0x888888FF);

	//vec2 dirEnd = m_position + getDirection() * m_scale.x * 4;
	//vec2 upEnd = m_position - perp(getDirection()) * m_scale.y * 4;

	//sfw::drawLine(m_position.x, m_position.y,
	//	dirEnd.x, dirEnd.y, RED);

	//sfw::drawLine(m_position.x, m_position.y,
	//	upEnd.x, upEnd.y, GREEN);
}