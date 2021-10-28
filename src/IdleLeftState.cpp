#include "../include/IdleLeftState.h"

PlayerState* IdleLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new WalkLeftState();
            break;
        case InputID::RIGHT:
            return new WalkRightState();
            break;
        case InputID::DOWN:
            return new CrouchingLeftState();
            break;
        case InputID::JUMP:
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

    return nullptr;
}

///////////////////////////////////////////////////////////////

void IdleLeftState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void IdleLeftState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("IDLE"));
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
}

///////////////////////////////////////////////////////////////

void IdleLeftState::exit(Player& p)
{
}
