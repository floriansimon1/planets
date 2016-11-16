#ifndef CONNECTION_RESPONSE_HANDLER_HPP
#define CONNECTION_RESPONSE_HANDLER_HPP

#include "../../network/message-handler.hpp"

struct ConnectionResponseHandler: MessageHandler {
    virtual void handle(Communicator &communicator, Message &message, AgentState &state) const;
};

#endif
