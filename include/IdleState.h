#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "OnGroundState.h"
class IdleState :
    public OnGroundState
{
	IdleState() = default;
	virtual ~IdleState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif