#include "../include/Player.h"
#include <iostream>
void Player::handleInput(InputEvent t_event)
{
	PlayerState* state = m_state->handleInput(t_event);

	if (state)
	{
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

///////////////////////////////////////////////////////////////

void Player::update()
{
	m_state->update(*this);
}

///////////////////////////////////////////////////////////////

void Player::draw(SDL_Renderer* t_renderer)
{
}
