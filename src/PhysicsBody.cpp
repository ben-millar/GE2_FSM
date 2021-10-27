#include "PhysicsBody.h"
#include <iostream>
void PhysicsBody::update()
{
	m_position += m_velocity;
	decelerate();

	std::cout << m_velocity.x << std::endl;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveLeft()
{
	m_velocity.x -= (MAX_SPEED / TIME_TO_MAX_SPEED) * 0.01666f * 2.0f;
	if (m_velocity.x < -MAX_SPEED)
		m_velocity = -MAX_SPEED;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveRight()
{
	m_velocity.x += (MAX_SPEED / TIME_TO_MAX_SPEED) * 0.01666 * 2.0f;
	if (m_velocity.x > MAX_SPEED)
		m_velocity.x = MAX_SPEED;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::decelerate()
{
	m_velocity.x -= m_velocity.x * float(MAX_SPEED / TIME_TO_FULL_STOP) * 0.01666f;
}
