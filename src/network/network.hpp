#ifndef NETWORK_HPP
#define NETWORK_HPP

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

#define preparePlanetsPacket(packet) \
    ((packet) << "PLANETS")

#endif
