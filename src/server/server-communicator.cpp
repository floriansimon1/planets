#include "../network/ports.hpp"
#include "../network/network.hpp"
#include "./server-communicator.hpp"
#include "./server-message-handlers-list.hpp"

ServerCommunicator::ServerCommunicator(): Communicator(serverHandlers()) {
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        throw SocketBindError();
    }

    socket.setBlocking(false);
}

void ServerCommunicator::broadcast(sf::Packet &&announcement) {
    socket.send(announcement, sf::IpAddress::Broadcast, BROADCAST_PORT);
}
