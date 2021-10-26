#pragma once
#include "OnGroundState.h"
class CrouchingState :
    public OnGroundState
{
public:
	CrouchingState() = default;
	virtual ~CrouchingState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};