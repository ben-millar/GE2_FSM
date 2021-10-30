#include "../include/CrouchingLeftState.h"

PlayerState* CrouchingLeftState::handleInput(InputEvent t_event)
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
        case InputID::DOWN:
            return new IdleLeftState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void CrouchingLeftState::update(Player& p, Time t_dT)
{
}

///////////////////////////////////////////////////////////////

void CrouchingLeftState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("CROUCH"));
    spr.setFrames(
        {
            SDL_Rect{0,0,32,32},
            SDL_Rect{0,32,32,32},
            SDL_Rect{0,64,32,32},
            SDL_Rect{0,96,32,32}
        }
    );

    p.getPhysicsBody().isCrouching(true);
}

///////////////////////////////////////////////////////////////

void CrouchingLeftState::exit(Player& p)
{
    p.getPhysicsBody().isCrouching(false);
}
