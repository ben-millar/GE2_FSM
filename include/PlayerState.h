#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

#include <iostream>
#include "InputEvent.h"
#include "TextureManager.h"
#include "AnimatedSprite.h"

class Player;

class PlayerState {
public:
	virtual ~PlayerState() {};
	virtual PlayerState* handleInput(InputEvent t_event) = 0;
	virtual void update(Player&, Time t_dT) = 0;
	virtual void enter(Player&) = 0;
	virtual void exit(Player&) = 0;
protected:
};

#include "Player.h"

#endif