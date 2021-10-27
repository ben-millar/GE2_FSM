#include "../include/WalkRightState.h"

PlayerState* WalkRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::DOWN:
            return new CrouchWalkRightState();
            break;
        default:
            break;
        }
    }
    else if (InputType::RELEASED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::RIGHT:
            return new IdleState();
            break;
        default:
            break;
        }
    }

    // If we didn't handle this event, pass up to our superstate
    return OnGroundState::handleInput(t_event);
}

///////////////////////////////////////////////////////////////

void WalkRightState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void WalkRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("WALK"));
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

void WalkRightState::exit(Player& p)
{
}
