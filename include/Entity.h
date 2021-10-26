#ifndef ENTITY_H
#define ENTITY_H

#include "InputEvent.h"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

    virtual void handleInput(InputEvent t_input) = 0;
    virtual void update() = 0;
    virtual void draw(SDL_Renderer* t_renderer) = 0;
};

#endif