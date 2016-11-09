#include "./server-communicator.hpp"
#include "./host.hpp"

ServerCommunicator::ServerCommunicator() {
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void ServerCommunicator::publish() {
    sf::Packet announcement;

    announcement
    << "PLANETS"
    << (sf::Uint16) SERVER_PORT
    << (sf::Uint8) world.players.size()
    << (sf::Uint8) maxPlayers;

    socket.send(announcement, sf::IpAddress::Broadcast, BROADCAST_PORT);
}

void ServerCommunicator::handleJoinRequest() {
    Host        host;
    std::string name;
    sf::Packet  joinRequest;

    while (socket.receive(joinRequest, host.address, host.port) == sf::Socket::Done) {
        std::string buffer;

        joinRequest
        >> buffer
        >> name;

        std::cout << name << std::endl;
    }
}
