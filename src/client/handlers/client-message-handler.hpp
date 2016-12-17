#ifndef CLIENT_MESSAGE_HANDLER_HPP
#define CLIENT_MESSAGE_HANDLER_HPP

#include "../../network/message.hpp"
#include "../../core/application.hpp"
#include "../../network/message-handler.hpp"

struct ClientMessageHandler: MessageHandler {
    // Adapter method that casts from application to client application.
    virtual void handle(Application &application, Message &message) const;

    virtual void doHandle(ClientApplication &application, Message &message) const = 0;
};

#endif
