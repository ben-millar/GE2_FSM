#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "OnGroundState.h"

class IdleState :
    public OnGroundState
{
public:
	IdleState() = default;
	virtual ~IdleState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "WalkLeftState.h"
#include "WalkRightState.h"
#include "CrouchingState.h"

#endif