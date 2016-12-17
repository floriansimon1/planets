#include "../network/ports.hpp"
#include "../network/network.hpp"
#include "./client-communicator.hpp"

ClientCommunicator::ClientCommunicator(): Communicator(clientHandlers()) {
    if (gameDiscoverySocket.bind(BROADCAST_PORT) != sf::Socket::Done) {
        throw SocketBindError();
    }

    bindToAnyAvailablePort(socket);

    socket.setBlocking(false);
    gameDiscoverySocket.setBlocking(false);
}
