#include "AnimatedSprite.h"
#include <iostream>
AnimatedSprite::AnimatedSprite(SDL_Rect t_rect) :
	m_sprite(t_rect)
{
	m_clock.start();
}

////////////////////////////////////////////////////////////

AnimatedSprite::~AnimatedSprite()
{
	SDL_DestroyTexture(m_texture);
}

////////////////////////////////////////////////////////////

void AnimatedSprite::setFrames(std::vector<SDL_Rect> t_frames)
{
	m_frames = t_frames;
	m_currentFrame = m_frames.begin();
}

////////////////////////////////////////////////////////////

void AnimatedSprite::update()
{
	if (m_clock.getTimeElapsed().asSeconds() > m_timePerFrame)
	{
		if (m_frames.end() == ++m_currentFrame)
			m_currentFrame = m_frames.begin();
		m_clock.restart();
	}
}

////////////////////////////////////////////////////////////

void AnimatedSprite::draw(SDL_Renderer* t_renderer)
{
	SDL_RenderCopy(t_renderer, m_texture, &*m_currentFrame, &m_sprite);
}
