#include "./network.hpp"

void bindToAnyAvailablePort(sf::UdpSocket &socket) {
    if (socket.bind(45007) != sf::Socket::Done) {
        throw SocketBindError();
    }
}

void preparePlanetsPacket(sf::Packet &packet) {
    packetWrite(packet, "PLANETS");
}

void packetTypeWrite(sf::Packet &packet, MessageType type) {
    packetWrite(packet, static_cast<std::underlying_type_t<MessageType>>(type));
}

void packetTypeRead(sf::Packet &packet, MessageType &type) {
    std::underlying_type_t<MessageType> t;

    packetRead(packet, t);

    type = static_cast<MessageType>(t);
}
