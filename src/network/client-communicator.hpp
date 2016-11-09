#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Network.hpp>

#include <string>
#include <vector>
#include <memory>

#include "./host.hpp"

struct ClientCommunicator {
    sf::UdpSocket socket;

    ClientCommunicator();

    void updateAvailableGamesList(std::vector<std::shared_ptr<Host>> &list);

    void joinGame(Host &game, const std::string &name);
};

#endif
