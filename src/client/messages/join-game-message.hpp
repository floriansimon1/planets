#ifndef JOIN_GAME_MESSAGE_HPP
#define JOIN_GAME_MESSAGE_HPP

#include <string>

#include "../../network/outgoing-message.hpp"

struct JoinGameMessage: OutgoingMessage {
    const unsigned short localPort;
    const std::string    name;

    JoinGameMessage(const Host &h, const std::string &n, unsigned short p);

    virtual void prepare();
};

#endif
