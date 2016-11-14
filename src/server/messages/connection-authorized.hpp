#ifndef CONNECTION_AUTHORIZED_HPP
#define CONNECTION_AUTHORIZED_HPP

#include "../../network/outgoing-message.hpp"

struct ConnectionAuthorized: OutgoingMessage {
    using OutgoingMessage::OutgoingMessage;

    virtual void prepare();
};

#endif
