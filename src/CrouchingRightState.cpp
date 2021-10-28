#include "../include/CrouchingRightState.h"

PlayerState* CrouchingRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new CrouchWalkLeftState();
            break;
        case InputID::RIGHT:
            return new CrouchWalkRightState();
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
        case InputID::DOWN:
            return new IdleRightState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void CrouchingRightState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void CrouchingRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("CROUCH"));
    spr.setFrames(
        {
            SDL_Rect{32,0,32,32},
            SDL_Rect{32,32,32,32},
            SDL_Rect{32,64,32,32},
            SDL_Rect{32,96,32,32}
        }
    );
}

///////////////////////////////////////////////////////////////

void CrouchingRightState::exit(Player& p)
{
}
