#ifndef CROUCHING_LEFT_STATE_H
#define CROUCHING_LEFT_STATE_H

#include "PlayerState.h"

class CrouchingLeftState :
    public PlayerState
{
public:
	CrouchingLeftState() = default;
	virtual ~CrouchingLeftState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&, Time t_dT) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "IdleLeftState.h"
#include "CrouchWalkLeftState.h"
#include "CrouchWalkRightState.h"
#include "JumpingLeftState.h"

#endif