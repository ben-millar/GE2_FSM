#ifndef WALK_LEFT_STATE_H
#define WALK_LEFT_STATE_H

#include "OnGroundState.h"

class WalkLeftState :
    public OnGroundState
{
public:
	WalkLeftState() = default;
	virtual ~WalkLeftState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "IdleState.h"
#include "CrouchWalkLeftState.h"

#endif