#ifndef RUN_RIGHT_STATE_H
#define RUN_RIGHT_STATE_H

#include "OnGroundState.h"

class RunRightState :
    public OnGroundState
{
public:
	RunRightState() = default;
	virtual ~RunRightState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif