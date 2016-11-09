#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <SFML/Network.hpp>

#include "../core/world.hpp"
#include "./host.hpp"

struct ServerCommunicator {
    const bool         exit       = false;
    const unsigned int maxPlayers = 5;

    std::vector<Host> clients;
    sf::UdpSocket     socket;
    World             world;

    ServerCommunicator();

    void serve();

    private:
        void handleJoinRequest();
        void publish();
};

#endif
