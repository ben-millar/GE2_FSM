#include "../include/Player.h"
#include <iostream>
void Player::handleInput(InputEvent t_event)
{
	if (InputID::NONE != t_event.ID)
		std::cout << (int)t_event.ID << std::endl;
}

void Player::update()
{

}

void Player::draw(SDL_Renderer* t_renderer)
{
}
