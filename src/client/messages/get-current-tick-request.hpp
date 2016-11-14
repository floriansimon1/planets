#ifndef GET_CURRENT_TICK_HPP
#define GET_CURRENT_TICK_HPP

#include "../../network/outgoing-message.hpp"

struct GetCurrentTickRequest: OutgoingMessage {
    using OutgoingMessage::OutgoingMessage;

    virtual void prepare();
};

#endif
