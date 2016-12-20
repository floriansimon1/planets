#ifndef SERVER_MESSAGE_HANDLER_HPP
#define SERVER_MESSAGE_HANDLER_HPP

#include "../../network/message.hpp"
#include "../server-application.hpp"
#include "../../network/message-handler.hpp"

struct ServerMessageHandler: MessageHandler {
    // Adapter method that casts from application to server application.
    virtual void handle(Application &application, Message &message) const;

    virtual void doHandle(ServerApplication &application, Message &message) const = 0;
};

#endif
