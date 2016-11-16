#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

struct PacketReadError {};
struct PacketWriteError {};

#define packetRead(packet, var) \
    if (!(packet >> var)) { \
        throw PacketReadError(); \
    }

#define packetWrite(packet, var) \
    if (!(packet << var)) { \
        throw PacketWriteError(); \
    }

#define preparePlanetsPacket(packet) packetWrite(packet, "PLANETS")

sf::Uint16 findAvailablePort();

#endif
