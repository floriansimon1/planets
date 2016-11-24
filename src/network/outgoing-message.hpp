#ifndef OUTGOING_MESSAGE
#define OUTGOING_MESSAGE

#include "./message.hpp"
#include "./host.hpp"

struct OutgoingMessage: Message {
    bool error = false;

    OutgoingMessage(const Host &h);

    void doPrepare();

    protected:
        virtual void prepare() {}

    private:
        bool prepared = false;
};

#endif
