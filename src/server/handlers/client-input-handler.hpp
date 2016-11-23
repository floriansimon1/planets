#ifndef CLIENT_INPUT_HPP
#define CLIENT_INPUT_HPP

#include "../../network/message-handler.hpp"

struct ClientInputHandler: MessageHandler {
    virtual void handle(Communicator &communicator, Message &message, AgentState &state) const;
};

#endif
