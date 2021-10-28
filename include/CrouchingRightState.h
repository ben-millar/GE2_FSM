#ifndef CROUCHING_RIGHT_STATE_H
#define CROUCHING_RIGHT_STATE_H

#include "PlayerState.h"

class CrouchingRightState :
    public PlayerState
{
public:
	CrouchingRightState() = default;
	virtual ~CrouchingRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "IdleRightState.h"
#include "CrouchWalkRightState.h"
#include "CrouchWalkLeftState.h"
#include "JumpingRightState.h"

#endif