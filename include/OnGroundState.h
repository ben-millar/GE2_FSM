#ifndef ON_GROUND_STATE_H
#define ON_GROUND_STATE_H

#include "PlayerState.h"

class OnGroundState :
    public PlayerState
{
public:
	OnGroundState() = default;
	virtual ~OnGroundState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#include "JumpingState.h"

#endif