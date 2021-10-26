#include "../include/RunRightState.h"

PlayerState* RunRightState::handleInput(InputEvent t_event)
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
        default:
            break;
        }
    }

    // If we didn't handle this event, pass up to our superstate
    return OnGroundState::handleInput(t_event);
}

///////////////////////////////////////////////////////////////

void RunRightState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void RunRightState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void RunRightState::exit(Player&)
{
}
