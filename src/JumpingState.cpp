#include "../include/JumpingState.h"

PlayerState* JumpingState::handleInput(InputEvent t_event)
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

void JumpingState::update(Player&)
{
}

///////////////////////////////////////////////////////////////

void JumpingState::enter(Player&)
{
}

///////////////////////////////////////////////////////////////

void JumpingState::exit(Player&)
{
}
