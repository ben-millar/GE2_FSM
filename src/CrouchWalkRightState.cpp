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

void CrouchWalkRightState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void CrouchWalkRightState::exit(Player&)
{
}
