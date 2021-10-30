#include "../include/JumpingRightState.h"

PlayerState* JumpingRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new JumpingLeftState();
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
            return new FallingRightState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void JumpingRightState::update(Player& p, Time t_dT)
{
    if (InputHandler::getInstance()->isPressed(InputID::RIGHT))
        p.getPhysicsBody().moveRight(t_dT);
}

///////////////////////////////////////////////////////////////

void JumpingRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("JUMP"));
    spr.setFrames(
        {
            SDL_Rect{32,0,32,32},
            SDL_Rect{32,32,32,32},
            SDL_Rect{32,64,32,32},
            SDL_Rect{32,96,32,32},
            SDL_Rect{32,128,32,32},
            SDL_Rect{32,160,32,32}
        }
    );

    p.getPhysicsBody().jump();
    spr.loop(false);
}

///////////////////////////////////////////////////////////////

void JumpingRightState::exit(Player& p)
{
    p.getAnimatedSprite().loop(true);
}
