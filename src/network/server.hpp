#ifndef SERVER_HPP
#define SERVER_HPP

#include <SFML/Network.hpp>

#include "../core/world.hpp"

struct Server {
    const unsigned int maxPlayers = 5;

    sf::UdpSocket socket;
    World         world;

    Server();

    void publish();
};

#endif
