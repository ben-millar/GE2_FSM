#include "../include/JumpingLeftState.h"

PlayerState* JumpingLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::RIGHT:
            return new JumpingRightState();
            break;
        default:
            break;
        }
    }
    else if (InputType::RELEASED == t_event.type)
    {
        switch (t_event.ID)
        {
        default:
            break;
        }
    }
    else
    {
        switch (t_event.ID)
        {
        case InputID::FALLING:
            return new FallingLeftState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void JumpingLeftState::update(Player& p, Time t_dT)
{
    if (InputHandler::getInstance()->isPressed(InputID::LEFT))
        p.getPhysicsBody().moveLeft(t_dT);
}

///////////////////////////////////////////////////////////////

void JumpingLeftState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("JUMP"));
    spr.setFrames(
        {
            SDL_Rect{0,0,32,32},
            SDL_Rect{0,32,32,32},
            SDL_Rect{0,64,32,32},
            SDL_Rect{0,96,32,32},
            SDL_Rect{0,128,32,32},
            SDL_Rect{0,160,32,32}
        }
    );

    p.getPhysicsBody().jump();
    spr.loop(false);
}

///////////////////////////////////////////////////////////////

void JumpingLeftState::exit(Player& p)
{
    p.getAnimatedSprite().loop(true);
}
