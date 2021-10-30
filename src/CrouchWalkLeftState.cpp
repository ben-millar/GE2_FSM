#include "../include/CrouchWalkLeftState.h"

PlayerState* CrouchWalkLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
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
            return new WalkLeftState();
            break;
        case InputID::LEFT:
            return new CrouchingLeftState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void CrouchWalkLeftState::update(Player& p, Time t_dT)
{
    if (InputHandler::getInstance()->isPressed(InputID::LEFT))
        p.getPhysicsBody().moveLeft(t_dT);
}

///////////////////////////////////////////////////////////////

void CrouchWalkLeftState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("CROUCH_WALK"));
    spr.setFrames(
        {
            SDL_Rect{0,0,32,32},
            SDL_Rect{0,32,32,32},
            SDL_Rect{0,64,32,32},
            SDL_Rect{0,96,32,32},
            SDL_Rect{0,128,32,32},
            SDL_Rect{0,160,32,32},
            SDL_Rect{0,192,32,32},
            SDL_Rect{0,224,32,32},
            SDL_Rect{0,256,32,32},
            SDL_Rect{0,288,32,32}
        }
    );

    p.getPhysicsBody().isCrouching(true);
}

///////////////////////////////////////////////////////////////

void CrouchWalkLeftState::exit(Player& p)
{
    p.getPhysicsBody().isCrouching(false);
}
