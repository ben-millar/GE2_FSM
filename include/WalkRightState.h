#ifndef WALK_RIGHT_STATE_H
#define WALK_RIGHT_STATE_H

#include "PlayerState.h"

class WalkRightState :
    public PlayerState
{
public:
	WalkRightState() = default;
	virtual ~WalkRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "IdleRightState.h"
#include "CrouchWalkRightState.h"
#include "JumpingRightState.h"

#endif