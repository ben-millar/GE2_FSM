#include "../include/CrouchWalkRightState.h"

PlayerState* CrouchWalkRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
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
            return new CrouchingState();
            break;
        default:
            break;
        }
    }

    // If we didn't handle this event, pass up to our superstate
    return OnGroundState::handleInput(t_event);
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::enter(Player& p)
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
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::exit(Player& p)
{
}
