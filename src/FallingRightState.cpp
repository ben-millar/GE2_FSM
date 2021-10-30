#include "../include/FallingRightState.h"

PlayerState* FallingRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new FallingLeftState();
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
        case InputID::HIT_GROUND:
            return new IdleRightState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void FallingRightState::update(Player& p, Time t_dT)
{
    if (InputHandler::getInstance()->isPressed(InputID::RIGHT))
        p.getPhysicsBody().moveRight(t_dT);
}

///////////////////////////////////////////////////////////////

void FallingRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("FALL"));
    spr.setFrames(
        {
            SDL_Rect{32,0,32,32},
            SDL_Rect{32,32,32,32},
            SDL_Rect{32,64,32,32}
        }
    );

    spr.loop(false);
}

///////////////////////////////////////////////////////////////

void FallingRightState::exit(Player& p)
{
    p.getAnimatedSprite().loop(true);
}
