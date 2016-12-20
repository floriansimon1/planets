#ifndef CONNECTION_REQUEST_HANDLER_HPP
#define CONNECTION_REQUEST_HANDLER_HPP

#include "./server-message-handler.hpp"

struct ConnectionRequestHandler: ServerMessageHandler {
    virtual void doHandle(ServerApplication &application, Message &message) const;
};

#endif
