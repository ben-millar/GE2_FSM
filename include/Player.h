#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "InputHandler.h"
#include "PlayerState.h"
#include "AnimatedSprite.h"
#include "PhysicsBody.h"

class Player : public Entity
{
public:
    Player();
    ~Player() = default;

    AnimatedSprite& getAnimatedSprite() { return m_animatedSprite; }
    PhysicsBody& getPhysicsBody() { return m_physicsBody; }

    void handleInput(InputEvent t_event) override;

    void update(Time t_dT) override;

    PlayerState* getPlayerState() { return m_state; }
    void setPlayerState(PlayerState* t_state);

private:
    InputHandler* p_inputHandler;
    PlayerState* m_state{ nullptr };
    PhysicsBody m_physicsBody;
    AnimatedSprite m_animatedSprite;
};

#endif