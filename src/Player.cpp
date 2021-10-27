#include "../include/Player.h"

Player::Player() :
	m_animatedSprite(SDL_Rect{400,400,128,128})
{
	p_inputHandler = InputHandler::getInstance();
	m_animatedSprite.setPosition(m_physicsBody.getPosition());
}

///////////////////////////////////////////////////////////////

void Player::handleInput(InputEvent t_event)
{
	PlayerState* state = m_state->handleInput(t_event);

	if (state)
		setPlayerState(state);
}

///////////////////////////////////////////////////////////////

void Player::update()
{
	m_state->update(*this);
	m_physicsBody.update();
	m_animatedSprite.update();
	m_animatedSprite.setPosition(m_physicsBody.getPosition());

	if (p_inputHandler->isPressed(InputID::LEFT))
		m_physicsBody.moveLeft();
	else if (p_inputHandler->isPressed(InputID::RIGHT))
		m_physicsBody.moveRight();
}

///////////////////////////////////////////////////////////////

void Player::setPlayerState(PlayerState* t_state)
{
	if (m_state)
	{
		m_state->exit(*this);
		delete m_state;
	}
	
	m_state = t_state;
	m_state->enter(*this);
}
