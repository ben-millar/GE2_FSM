#ifndef RUN_LEFT_STATE_H
#define RUN_LEFT_STATE_H

#include "OnGroundState.h"

class RunLeftState :
    public OnGroundState
{
public:
	RunLeftState() = default;
	virtual ~RunLeftState() = default;
	virtual PlayerState* handleInput(InputEvent t_event) override;
	virtual void update(Player&) override;
	virtual void enter(Player&) override;
	virtual void exit(Player&) override;
};

#endif