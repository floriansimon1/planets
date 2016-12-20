#ifndef GET_CURRENT_TICK_HANDLER
#define GET_CURRENT_TICK_HANDLER

#include "./server-message-handler.hpp"

struct GetCurrentTickHandler: ServerMessageHandler {
    virtual void doHandle(ServerApplication &application, Message &message) const;
};

#endif
