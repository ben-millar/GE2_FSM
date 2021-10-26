#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include <stack>
#include "Command.h"

class MacroCommand
{
public:
    MacroCommand() = default;
    ~MacroCommand() = default;

    void execute(Command* t_command) {
        m_done.push(t_command);
        m_done.top()->execute();
        std::stack<Command*>().swap(m_undone);
    }

    void undo() {
        if (m_done.size()) {
            Command* c = m_done.top();
            m_done.pop();
            m_undone.push(c);
            m_undone.top()->undo();
        }
    }

    void redo() {
        if (m_undone.size()) {
            Command* c = m_undone.top();
            m_undone.pop();
            m_done.push(c);
            m_done.top()->execute();
        }
    }

private:
    // I'm using a straightforward two stack approach here. A cleaner implementation would be a doubly linked-list,
    // with unique_ptrs going forward, and weak_ptrs going back. This would allow an 'append' operation to add onto
    // the list, an 'undo' option to step back along the list, and a 'redo' operation to step forward along the list.
    // This way, if we undo n commands and then append a new command to HEAD->next, we will break the unique_ptr to
    // the 'old' future, and they will implicitly delete in a cascade.
    std::stack<Command*> m_done;
    std::stack<Command*> m_undone;
};

#endif