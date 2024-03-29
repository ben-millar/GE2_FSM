#ifndef CROUCH_WALK_RIGHT_STATE_H
#define CROUCH_WALK_RIGHT_STATE_H

#include "PlayerState.h"

class CrouchWalkRightState :
    public PlayerState
{
public:
	CrouchWalkRightState() = default;
	virtual ~CrouchWalkRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&, Time t_dT) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "CrouchingRightState.h"
#include "WalkRightState.h"
#include "JumpingRightState.h"

#endif