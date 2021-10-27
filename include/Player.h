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

    AnimatedSprite& getAnimatedSprite() { return m_animatedSprite; }

    void handleInput(InputEvent t_event) override;

    void update() override;

    PlayerState* getPlayerState() { return m_state; }
    void setPlayerState(PlayerState* t_state);

private:
    PlayerState* m_state{ nullptr };

    AnimatedSprite m_animatedSprite;
};

#endif