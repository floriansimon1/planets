#ifndef MESSAGE_HANDLER_HPP
#define MESSAGE_HANDLER_HPP

#include "../core/application.hpp"
#include "./message.hpp"

struct MessageHandler {
    virtual void handle(Application &application, Message &message) const = 0;
};

#endif
