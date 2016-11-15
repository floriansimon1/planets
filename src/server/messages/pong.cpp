#include "./pong.hpp"
#include "../../network/network.hpp"

Pong::Pong(const Host &h, const sf::Clock &worldClock): OutgoingMessage(h) {
    packetWrite(packet, worldClock.getElapsedTime().asMilliseconds());
}
