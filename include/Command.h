#ifndef COMMAND_H
#define COMMAND_H

#include "Entity.h"

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
protected:
    Entity* target;
    Command(Entity* e) : target{e} {}
};

#endif