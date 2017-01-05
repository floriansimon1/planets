#ifndef PONG_HPP
#define PONG_HPP

#include <SFML/System.hpp>

#include "../../network/host.hpp"
#include "../states/serve-game.hpp"
#include "../../network/network.hpp"
#include "../../network/outgoing-message.hpp"

struct Pong: OutgoingMessage {
    Pong(const Host &h, const Id requestId, const ServeGame &state);
};

#endif
