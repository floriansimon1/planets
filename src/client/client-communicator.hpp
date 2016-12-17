#ifndef CLIENT_COMMUNICATOR_HPP
#define CLIENT_COMMUNICATOR_HPP

#include <SFML/Network.hpp>

#include "../network/communicator.hpp"

struct ClientCommunicator: Communicator {
    sf::UdpSocket gameDiscoverySocket;

    ClientCommunicator();
};

#endif
