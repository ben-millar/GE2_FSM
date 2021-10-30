#include "../include/Player.h"

Player::Player() :
	m_animatedSprite(SDL_Rect{400,400,128,128}),
	m_physicsBody(250.0f)
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

void Player::update(Time t_dT)
{
	m_state->update(*this, t_dT);
	m_physicsBody.update(t_dT);
	m_animatedSprite.update();
	m_animatedSprite.setPosition(m_physicsBody.getPosition());
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
