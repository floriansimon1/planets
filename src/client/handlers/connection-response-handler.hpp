#ifndef CONNECTION_RESPONSE_HANDLER_HPP
#define CONNECTION_RESPONSE_HANDLER_HPP

#include "./client-message-handler.hpp"

struct ConnectionResponseHandler: ClientMessageHandler {
    virtual void handle(ClientApplication &application, Message &message) const;
};

#endif
