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

void WalkLeftState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void WalkLeftState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void WalkLeftState::exit(Player&)
{
}
