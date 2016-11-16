#ifndef JOIN_GAME_HPP
#define JOIN_GAME_HPP

#include <string>

#include "../../network/outgoing-message.hpp"

struct JoinGame: OutgoingMessage {
    const unsigned short localPort;
    const std::string    name;

    JoinGame(const Host &h, const std::string &n, unsigned short p);

    virtual void prepare();
};

#endif
