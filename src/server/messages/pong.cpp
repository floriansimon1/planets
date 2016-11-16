#include "./pong.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

Pong::Pong(const Host &h, const Id requestId, const sf::Clock &worldClock): OutgoingMessage(h) {
    packetWrite(packet, PING);
    packetWrite(packet, requestId);
    packetWrite(packet, worldClock.getElapsedTime().asMilliseconds());
}
