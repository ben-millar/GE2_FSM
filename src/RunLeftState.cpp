#include "../include/RunLeftState.h"

PlayerState* RunLeftState::handleInput(InputEvent t_event)
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

void RunLeftState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void RunLeftState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void RunLeftState::exit(Player&)
{
}
