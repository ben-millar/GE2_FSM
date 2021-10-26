#include "../include/CrouchingState.h"

PlayerState* CrouchingState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new CrouchWalkLeftState();
            break;
        case InputID::RIGHT:
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
        case InputID::DOWN:
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

void CrouchingState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchingState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchingState::exit(Player&)
{
}
