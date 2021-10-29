#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <vector>
#include "Clock.h"
#include "PhysicsBody.h"
#include <iostream>

class AnimatedSprite
{
public:
	AnimatedSprite(SDL_Rect t_rect = SDL_Rect());
	~AnimatedSprite();

	void setTexture(SDL_Texture* t_texture) { m_texture = t_texture; }
	void setFrames(std::vector<SDL_Rect> t_frames);
	void setFrameDelay(float t_timePerFrame) { m_timePerFrame = t_timePerFrame; }
	void loop(bool t_shouldLoop) { m_loop = t_shouldLoop; }

	void setPosition(Vector2 t_pos) { m_sprite.x = t_pos.x, m_sprite.y = t_pos.y; }

	void update();

	void draw(SDL_Renderer* t_renderer);

private:
	SDL_Texture* m_texture{ nullptr };
	SDL_Rect m_sprite;
	std::vector<SDL_Rect>::iterator m_currentFrame;

	std::vector<SDL_Rect> m_frames;

	bool m_loop{ true };

	Clock m_clock;
	float m_timePerFrame{ 0.1f };
};

#endif