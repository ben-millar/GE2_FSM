#ifndef WALK_RIGHT_STATE_H
#define WALK_RIGHT_STATE_H

#include "OnGroundState.h"

class WalkRightState :
    public OnGroundState
{
public:
	WalkRightState() = default;
	virtual ~WalkRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "IdleState.h"
#include "CrouchWalkRightState.h"

#endif