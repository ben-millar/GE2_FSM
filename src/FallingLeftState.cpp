#include "../include/FallingLeftState.h"

PlayerState* FallingLeftState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::JUMP:
            return new IdleLeftState();
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

void FallingLeftState::update(Player& p)
{
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
            SDL_Rect{0,64,32,32},
            SDL_Rect{0,96,32,32},
            SDL_Rect{0,128,32,32},
            SDL_Rect{0,160,32,32}
        }
    );
}

///////////////////////////////////////////////////////////////

void FallingLeftState::exit(Player& p)
{
}
