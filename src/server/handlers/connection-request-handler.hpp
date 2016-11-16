#ifndef CONNECTION_REQUEST_HANDLER_HPP
#define CONNECTION_REQUEST_HANDLER_HPP

#include "../../network/message.hpp"
#include "../../core/agent-state.hpp"
#include "../../network/communicator.hpp"
#include "../../network/message-handler.hpp"

struct ConnectionRequestHandler: MessageHandler {
    virtual void handle(Communicator &communicator, Message &message, AgentState &state) const;
};

#endif
