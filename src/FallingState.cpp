#include "../include/FallingState.h"

PlayerState* FallingState::handleInput(InputEvent t_event)
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

    return nullptr;
}

///////////////////////////////////////////////////////////////

void FallingState::update(Player&p, Time t_dT)
{
}

///////////////////////////////////////////////////////////////

void FallingState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void FallingState::exit(Player&)
{
}
