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

void WalkRightState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void WalkRightState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void WalkRightState::exit(Player&)
{
}
