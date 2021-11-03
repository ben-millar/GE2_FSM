#include "PhysicsBody.h"
#include <iostream>
void PhysicsBody::update(Time t_dT)
{
	m_position += m_velocity;
	decelerate(t_dT);

	if (m_velocity.y < 0.0f)
		InputHandler::getInstance()->onNotify(InputEvent(InputID::FALLING));
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveLeft(Time t_dT)
{
	float moveSpeed =
		(m_isCrouching) ?
		-MAX_SPEED * 0.4f :
		-MAX_SPEED;

	m_velocity.x = moveSpeed * t_dT.asSeconds();
	//float deltaSpeed = ACCELERATION * t_dT.asSeconds();
	//((m_velocity.x - deltaSpeed) < -MAX_SPEED) ?
	//	m_velocity.x = -MAX_SPEED :
	//	m_velocity.x -= deltaSpeed;
		
}

///////////////////////////////////////////////////////////////

void PhysicsBody::moveRight(Time t_dT)
{
	float moveSpeed =
		(m_isCrouching) ?
		MAX_SPEED * 0.4f :
		MAX_SPEED;

	m_velocity.x = moveSpeed * t_dT.asSeconds();
	//float deltaSpeed = ACCELERATION * t_dT.asSeconds() * 2.0f;
	//(m_velocity.x + deltaSpeed > MAX_SPEED) ?
	//	m_velocity.x = MAX_SPEED :
	//	m_velocity.x += deltaSpeed;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::jump()
{
	m_velocity.y += JUMP_FORCE;
}

///////////////////////////////////////////////////////////////

void PhysicsBody::decelerate(Time t_dT)
{
	m_velocity.x -= (MAX_SPEED / 5.0f) * m_velocity.x * t_dT.asSeconds();

	if (m_position.y < GROUND_LEVEL)
	{
		m_velocity.y += GRAVITY * t_dT.asSeconds();
	}
	else
	{
		InputHandler::getInstance()->onNotify(InputEvent(InputID::HIT_GROUND));
		m_position.y = GROUND_LEVEL;
		m_velocity.y = 0.0f;
	}

	//m_velocity.x -= m_velocity.x * DECELERATION * t_dT.asSeconds();
	//if (m_velocity.x < 0.01f)
	//	m_velocity.x = 0.0f;
}
