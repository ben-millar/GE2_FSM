#include "PhysicsBody.h"
#include <iostream>
void PhysicsBody::update(Time t_dT)
{
	m_position += m_velocity;
	decelerate(t_dT);
	//std::cout << m_velocity.x << std::endl;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveLeft(Time t_dT)
{
	m_velocity.x = -MAX_SPEED;
	//float deltaSpeed = ACCELERATION * t_dT.asSeconds();
	//((m_velocity.x - deltaSpeed) < -MAX_SPEED) ?
	//	m_velocity.x = -MAX_SPEED :
	//	m_velocity.x -= deltaSpeed;
		
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveRight(Time t_dT)
{
	m_velocity.x = MAX_SPEED;
	//float deltaSpeed = ACCELERATION * t_dT.asSeconds() * 2.0f;
	//(m_velocity.x + deltaSpeed > MAX_SPEED) ?
	//	m_velocity.x = MAX_SPEED :
	//	m_velocity.x += deltaSpeed;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::decelerate(Time t_dT)
{
	m_velocity.x -= (MAX_SPEED / 5.0f) * m_velocity.x;
	//m_velocity.x -= m_velocity.x * DECELERATION * t_dT.asSeconds();
	//if (m_velocity.x < 0.01f)
	//	m_velocity.x = 0.0f;
}
