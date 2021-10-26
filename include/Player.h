#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Entity.h"

class Player : public Entity
{
public:
    Player() = default;
    ~Player() = default;

    void handleInput(InputEvent t_event) override;

    void update() override;

    void draw(SDL_Renderer* t_renderer) override;

private:
};

#endif