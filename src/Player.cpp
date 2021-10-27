#include "../include/Player.h"

Player::Player() :
	m_animatedSprite(SDL_Rect{400,400,128,128})
{
	m_clock.start();
	m_animatedSprite.setFrames(
		{
			SDL_Rect{0,0,32,32},
			SDL_Rect{0,32,32,32},
			SDL_Rect{0,64,32,32},
			SDL_Rect{0,96,32,32},
			SDL_Rect{0,128,32,32},
			SDL_Rect{0,160,32,32}
		}
	);
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

void Player::draw(SDL_Renderer* t_renderer)
{
	m_animatedSprite.draw(t_renderer);
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
