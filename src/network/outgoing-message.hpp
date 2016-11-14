#ifndef OUTGOING_MESSAGE
#define OUTGOING_MESSAGE

#include "./message.hpp"
#include "./host.hpp"

struct OutgoingMessage: Message {
    OutgoingMessage(const Host &h);

    protected:
        virtual void prepare() {}
};

#endif
