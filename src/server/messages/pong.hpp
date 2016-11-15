#ifndef PONG_HPP
#define PONG_HPP

#include <SFML/System.hpp>

#include "../../network/host.hpp"
#include "../../network/outgoing-message.hpp"

struct Pong: OutgoingMessage {
    Pong(const Host &h, const sf::Clock &worldClock);
};

#endif
