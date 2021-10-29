#include "../include/CrouchWalkRightState.h"

PlayerState* CrouchWalkRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new CrouchWalkLeftState();
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
            return new WalkRightState();
            break;
        case InputID::RIGHT:
            return new CrouchingRightState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::update(Player& p)
{
    if (InputHandler::getInstance()->isPressed(InputID::RIGHT))
        p.getPhysicsBody().moveRight(1.0f);
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("CROUCH_WALK"));
    spr.setFrames(
        {
            SDL_Rect{32,0,32,32},
            SDL_Rect{32,32,32,32},
            SDL_Rect{32,64,32,32},
            SDL_Rect{32,96,32,32},
            SDL_Rect{32,128,32,32},
            SDL_Rect{32,160,32,32},
            SDL_Rect{32,192,32,32},
            SDL_Rect{32,224,32,32},
            SDL_Rect{32,256,32,32},
            SDL_Rect{32,288,32,32}
        }
    );

    p.getPhysicsBody().isCrouching(true);
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::exit(Player& p)
{
    p.getPhysicsBody().isCrouching(false);
}
