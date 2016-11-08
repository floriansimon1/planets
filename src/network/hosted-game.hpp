#ifndef HOSTED_GAME_HPP
#define HOSTED_GAME_HPP

#include <SFML/Network.hpp>
#include <SFML/System.hpp>

struct HostedGame {
    unsigned short port;
    sf::IpAddress  host;
    sf::Clock      lastSeen;

    HostedGame() {}
    HostedGame(unsigned short p, sf::IpAddress &h): port(p), host(h) {}

    bool operator==(const HostedGame &g) const;
};

#endif
