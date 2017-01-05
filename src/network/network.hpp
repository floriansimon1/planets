#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <type_traits>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "../boilerplate/id.hpp"
#include "./message-types.hpp"

// In ms.
#define TICK_DELAY ((sf::Int32) 20)

struct SocketBindError {};
struct PacketReadError {};
struct PacketWriteError {};

template <typename T>
void packetRead(sf::Packet &packet, T &var) {
    if (!(packet >> var)) {
        throw PacketReadError();
    }
}

template <typename T>
void packetWrite(sf::Packet &packet, const T &var) {
    if (!(packet << var)) {
        throw PacketWriteError();
    }
}

void packetTypeWrite(sf::Packet &packet, MessageType type);

void packetTypeRead(sf::Packet &packet, MessageType &type);

void preparePlanetsPacket(sf::Packet &packet);

void bindToAnyAvailablePort(sf::UdpSocket &s);

#endif
