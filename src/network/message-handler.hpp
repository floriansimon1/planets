#ifndef MESSAGE_HANDLER_HPP
#define MESSAGE_HANDLER_HPP

#include "./message.hpp"

struct AgentState;
struct Communicator;

struct MessageHandler {
    virtual void handle(Communicator &communicator, Message &message, AgentState &state) const = 0;
};

#endif
