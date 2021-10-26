#include "../include/IdleState.h"

PlayerState* IdleState::handleInput(InputEvent t_event)
{
    if (InputType::PRESSED == t_event.type)
    {
        switch (t_event.ID)
        {
        case InputID::LEFT:
            return new WalkLeftState();
            break;
        case InputID::RIGHT:
            return new WalkRightState();
            break;
        case InputID::DOWN:
            return new CrouchingState();
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

    // If we didn't handle this event, pass up to our superstate
    return OnGroundState::handleInput(t_event);
}

///////////////////////////////////////////////////////////////

void IdleState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void IdleState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void IdleState::exit(Player&)
{
}
