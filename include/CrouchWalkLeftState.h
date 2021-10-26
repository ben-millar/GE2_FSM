#ifndef CROUCH_WALK_LEFT_STATE_H
#define CROUCH_WALK_LEFT_STATE_H

#include "OnGroundState.h"

class CrouchWalkLeftState :
	public OnGroundState
{
	CrouchWalkLeftState() = default;
	virtual ~CrouchWalkLeftState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif