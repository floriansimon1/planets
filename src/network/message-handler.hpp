#ifndef MESSAGE_HANDLER_HPP
#define MESSAGE_HANDLER_HPP

#include "./message.hpp"
#include "../core/agent-state.hpp"

struct MessageHandler {
    virtual void handle(Message &message, AgentState *state) = 0;
};

#endif
