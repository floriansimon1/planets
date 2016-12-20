#ifndef CLIENT_INPUT_HANDLER_HPP
#define CLIENT_INPUT_HANDLER_HPP

#include "./server-message-handler.hpp"

struct ClientInputHandler: ServerMessageHandler {
    virtual void doHandle(ServerApplication &application, Message &message) const;
};

#endif
