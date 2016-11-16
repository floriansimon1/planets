#ifndef JOIN_GAME_HPP
#define JOIN_GAME_HPP

#include <string>

#include "../../network/outgoing-message.hpp"

struct JoinGame: OutgoingMessage {
    const std::string name;

    JoinGame(const Host &h, const std::string &n);

    virtual void prepare();
};

#endif
