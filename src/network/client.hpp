#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Network.hpp>

#include <vector>
#include <memory>

#include "./hosted-game.hpp"

struct Client {
    sf::UdpSocket socket;

    Client();

    void updateAvailableGamesList(std::vector<std::shared_ptr<HostedGame>> &list);

    void joinGame(HostedGame &game);
};

#endif
