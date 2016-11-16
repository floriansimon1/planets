#include "./network.hpp"

void bindToAnyAvailablePort(sf::UdpSocket &socket) {
    if (socket.bind(45007) != sf::Socket::Done) {
        throw SocketBindError();
    }
}
