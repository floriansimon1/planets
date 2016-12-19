#ifndef MESSAGE_HANDLER_HPP
#define MESSAGE_HANDLER_HPP

#include "./message.hpp"

struct Application;

struct MessageHandler {
    virtual void handle(Application &application, Message &message) const = 0;
};

#endif
