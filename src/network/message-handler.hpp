#ifndef MESSAGE_HANDLER_HPP
#define MESSAGE_HANDLER_HPP

#include "./message.hpp"
#include "./communicator.hpp"
#include "../core/agent-state.hpp"

struct Communicator;

struct MessageHandler {
    virtual void handle(Communicator *communicator, Message &message, AgentState *state) = 0;
};

#endif
