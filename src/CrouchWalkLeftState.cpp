#include "../include/CrouchWalkLeftState.h"

PlayerState* CrouchWalkLeftState::handleInput(InputEvent t_event)
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
            return new WalkLeftState();
            break;
        case InputID::LEFT:
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

void CrouchWalkLeftState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchWalkLeftState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchWalkLeftState::exit(Player&)
{
}
