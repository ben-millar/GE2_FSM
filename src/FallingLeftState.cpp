#include "../include/FallingLeftState.h"

PlayerState* FallingLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::RIGHT:
            return new FallingRightState();
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
            return new IdleLeftState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void FallingLeftState::update(Player& p)
{
    if (InputHandler::getInstance()->isPressed(InputID::LEFT))
        p.getPhysicsBody().moveLeft(1.0f);
}

///////////////////////////////////////////////////////////////

void FallingLeftState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("FALL"));
    spr.setFrames(
        {
            SDL_Rect{0,0,32,32},
            SDL_Rect{0,32,32,32},
            SDL_Rect{0,64,32,32}
        }
    );

    spr.loop(false);
}

///////////////////////////////////////////////////////////////

void FallingLeftState::exit(Player& p)
{
    p.getAnimatedSprite().loop(true);
}
