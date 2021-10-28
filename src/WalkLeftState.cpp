#include "../include/WalkLeftState.h"

PlayerState* WalkLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::DOWN:
            return new CrouchWalkLeftState();
            break;
        default:
            break;
        }
    }
    else if (InputType::RELEASED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new IdleLeftState();
            break;
        case InputID::JUMP:
            return new JumpingLeftState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void WalkLeftState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void WalkLeftState::enter(Player& p)
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

void WalkLeftState::exit(Player& p)
{
}
