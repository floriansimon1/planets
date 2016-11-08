#include "./server.hpp"

Server::Server() {
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void Server::publish() {
    sf::Packet announcement;

    announcement
    << "PLANETS"
    << (sf::Uint16) SERVER_PORT
    << (sf::Uint8) world.players.size()
    << (sf::Uint8) maxPlayers;

    socket.send(announcement, sf::IpAddress::Broadcast, BROADCAST_PORT);
}
