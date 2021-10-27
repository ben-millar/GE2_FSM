#include "../include/OnGroundState.h"

PlayerState* OnGroundState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::JUMP:
            return new JumpingState();
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

void OnGroundState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void OnGroundState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void OnGroundState::exit(Player&)
{
}
