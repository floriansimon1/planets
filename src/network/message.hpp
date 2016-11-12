#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <SFML/Network.hpp>

#include "./host.hpp"

struct Message {
    Host       host;
    sf::Packet packet;
};

#endif
