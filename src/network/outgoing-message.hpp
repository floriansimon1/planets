#ifndef OUTGOING_MESSAGE
#define OUTGOING_MESSAGE

#include "./message.hpp"
#include "./host.hpp"

struct OutgoingMessage: Message {
    OutgoingMessage(const Host &h);

    void tryPrepare();

    protected:
        virtual void prepare() {}

    private:
        bool prepared = false;
};

#endif
