#ifndef ENTITY_H
#define ENTITY_H

#include "InputEvent.h"
#include "Clock.h"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

    virtual void handleInput(InputEvent t_input) = 0;
    virtual void update(Time t_dT) = 0;
};

#endif