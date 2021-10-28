#include "../include/FallingRightState.h"

PlayerState* FallingRightState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::JUMP:
            return new IdleRightState();
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

void FallingRightState::update(Player& p)
{
}

///////////////////////////////////////////////////////////////

void FallingRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("FALL"));
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

void FallingRightState::exit(Player& p)
{
}
