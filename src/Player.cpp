#include "../include/Player.h"

Player::Player() :
	m_animatedSprite(SDL_Rect{400,400,128,128})
{
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
	m_animatedSprite.update();
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
