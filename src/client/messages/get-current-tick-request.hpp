#ifndef GET_CURRENT_TICK_HPP
#define GET_CURRENT_TICK_HPP

#include "../../network/host.hpp"
#include "../../network/network.hpp"
#include "../../network/outgoing-message.hpp"

struct GetCurrentTickRequest: OutgoingMessage {
    Id requestId;

    GetCurrentTickRequest(const Host &h, Id id): OutgoingMessage(h), requestId(id) {}

    virtual void prepare();
};

#endif
