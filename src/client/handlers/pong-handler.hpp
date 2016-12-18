#ifndef PONG_HANDLER
#define PONG_HANDLER

#include "./client-message-handler.hpp"

struct PongHandler: ClientMessageHandler {
    virtual void doHandle(ClientApplication &application, Message &message) const;
};

#endif
