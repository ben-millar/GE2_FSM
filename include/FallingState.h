#ifndef FALLING_STATE_H
#define FALLING_STATE_H

#include "PlayerState.h"

class FallingState :
	public PlayerState
{
public:
	FallingState() = default;
	virtual ~FallingState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif