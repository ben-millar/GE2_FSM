#ifndef JUMPING_STATE_H
#define JUMPING_STATE_H

#include "PlayerState.h"

class JumpingState :
    public PlayerState
{
	JumpingState() = default;
	virtual ~JumpingState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif