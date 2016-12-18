#ifndef CONNECTION_RESPONSE_HANDLER_HPP
#define CONNECTION_RESPONSE_HANDLER_HPP

#include "./client-message-handler.hpp"

struct ConnectionResponseHandler: ClientMessageHandler {
    virtual void doHandle(ClientApplication &application, Message &message) const;
};

#endif
