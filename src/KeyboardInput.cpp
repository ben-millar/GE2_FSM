#include "../include/KeyboardInput.h"

KeyboardInput::KeyboardInput()
{
	initialiseMap();
}

///////////////////////////////////////////////////////////////

void KeyboardInput::initialiseMap()
{
	m_mapping.emplace(SDLK_UP, InputID::UP);
	m_mapping.emplace(SDLK_w, InputID::UP);
	m_mapping.emplace(SDLK_DOWN, InputID::DOWN);
	m_mapping.emplace(SDLK_s, InputID::DOWN);
	m_mapping.emplace(SDLK_LEFT, InputID::LEFT);
	m_mapping.emplace(SDLK_a, InputID::LEFT);
	m_mapping.emplace(SDLK_RIGHT, InputID::RIGHT);
	m_mapping.emplace(SDLK_d, InputID::RIGHT);
	m_mapping.emplace(SDLK_SPACE, InputID::JUMP);
	m_mapping.emplace(SDLK_ESCAPE, InputID::EXIT);
}

///////////////////////////////////////////////////////////////

void KeyboardInput::handleInput(SDL_Event t_event)
{
	if (t_event.key.repeat == m_keyRepeatEnabled &&
		(SDL_KEYDOWN == t_event.type ||
		 SDL_KEYUP == t_event.type))
	{
		auto it = m_mapping.find(t_event.key.keysym.sym);

		if (m_mapping.end() != it)
		{
			InputEvent e;

			// Set input ID
			e.ID = it->second;

			// Set Input Type
			e.type = (SDL_KEYDOWN == t_event.type) ? InputType::PRESSED : InputType::RELEASED;

			// Send our input notification
			notify(e);
		}
	}
}