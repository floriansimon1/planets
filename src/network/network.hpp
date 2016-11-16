#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

struct SocketBindError {};
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

// An ID number that can be sent over the wire safely via packet stream operations.
typedef sf::Uint16 Id;

void bindToAnyAvailablePort(sf::UdpSocket &s);

#endif
