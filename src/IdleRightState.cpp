#include "../include/IdleRightState.h"

PlayerState* IdleRightState::handleInput(InputEvent t_event)
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
            return new CrouchingRightState();
            break;
        case InputID::JUMP:
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

    return nullptr;
}

///////////////////////////////////////////////////////////////

void IdleRightState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void IdleRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("IDLE"));
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
}

///////////////////////////////////////////////////////////////

void IdleRightState::exit(Player& p)
{
}
