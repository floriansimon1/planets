#ifndef SERVER_COMMUNICATOR_HPP
#define SERVER_COMMUNICATOR_HPP

#include "../network/communicator.hpp"

struct ServerApplication;

struct ServerCommunicator: Communicator {
    ServerCommunicator();

    void broadcast(sf::Packet &&packet);
};

#endif
