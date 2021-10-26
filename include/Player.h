#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Entity.h"
#include "PlayerState.h"

class Player : public Entity
{
public:
    Player() = default;
    ~Player() = default;

    void handleInput(InputEvent t_event) override;

    void update() override;

    void draw(SDL_Renderer* t_renderer) override;

    PlayerState* getPlayerState() { return m_state; }
    void setPlayerState(PlayerState* t_state) { m_state = t_state; }

private:

    PlayerState* m_state{ nullptr };
};

#endif