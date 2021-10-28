#ifndef RUN_LEFT_STATE_H
#define RUN_LEFT_STATE_H

#include "PlayerState.h"

class RunLeftState :
    public PlayerState
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