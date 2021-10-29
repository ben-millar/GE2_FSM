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
        case InputID::LEFT:
            return new WalkLeftState();
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
        case InputID::RIGHT:
            return new IdleRightState();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

///////////////////////////////////////////////////////////////

void WalkRightState::update(Player& p)
{
    if (InputHandler::getInstance()->isPressed(InputID::RIGHT))
        p.getPhysicsBody().moveRight(1.0f);

    if (InputHandler::getInstance()->isPressed(InputID::DOWN))
        p.setPlayerState(new CrouchWalkRightState());
}

///////////////////////////////////////////////////////////////

void WalkRightState::enter(Player& p)
{
    AnimatedSprite& spr = p.getAnimatedSprite();
    spr.setTexture(TextureManager::getInstance()->get("WALK"));
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
}

///////////////////////////////////////////////////////////////

void WalkRightState::exit(Player& p)
{
}
