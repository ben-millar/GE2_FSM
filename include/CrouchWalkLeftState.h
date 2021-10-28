#ifndef CROUCH_WALK_LEFT_STATE_H
#define CROUCH_WALK_LEFT_STATE_H

#include "PlayerState.h"

class CrouchWalkLeftState :
	public PlayerState
{
public:
	CrouchWalkLeftState() = default;
	virtual ~CrouchWalkLeftState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "CrouchingLeftState.h"
#include "WalkLeftState.h"
#include "JumpingLeftState.h"

#endif