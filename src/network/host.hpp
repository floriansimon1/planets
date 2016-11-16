#ifndef HOSTED_GAME_HPP
#define HOSTED_GAME_HPP

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <string>

struct Host {
    unsigned short port;
    sf::IpAddress  address;
    sf::Clock      lastSeen;

    Host() {}
    Host(unsigned short p, sf::IpAddress &a): port(p), address(a) {}

    std::string toString() const;
    bool operator==(const Host &g) const;
};

#endif
