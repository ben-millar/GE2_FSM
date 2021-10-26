#ifndef CROUCH_WALK_RIGHT_STATE_H
#define CROUCH_WALK_RIGHT_STATE_H

#include "OnGroundState.h"

class CrouchWalkRightState :
    public OnGroundState
{
public:
	CrouchWalkRightState() = default;
	virtual ~CrouchWalkRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "CrouchingState.h"
#include "WalkRightState.h"

#endif