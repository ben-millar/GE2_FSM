#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "PlayerState.h"
#include "AnimatedSprite.h"

class Player : public Entity
{
public:
    Player();
    ~Player() = default;

    void setTexture(SDL_Texture* t_texture) { m_animatedSprite.setTexture(t_texture); }

    void handleInput(InputEvent t_event) override;

    void update() override;

    void draw(SDL_Renderer* t_renderer) override;

    PlayerState* getPlayerState() { return m_state; }
    void setPlayerState(PlayerState* t_state);

private:
    PlayerState* m_state{ nullptr };

    AnimatedSprite m_animatedSprite;

    Clock m_clock;
};

#endif