#ifndef MESSAGE_TYPES_HPP
#define MESSAGE_TYPES_HPP

#include <SFML/System.hpp>

enum class MessageType: sf::Uint16 {
    Ping               = 0,
    ClientInput        = 1,
    ConnectionRequest  = 2,
    ConnectionResponse = 3
};

#endif
