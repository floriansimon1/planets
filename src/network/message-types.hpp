#ifndef MESSAGE_TYPES_HPP
#define MESSAGE_TYPES_HPP

#include <SFML/System.hpp>

typedef sf::Uint16 MessageType;

#define PING                ((sf::Uint16) 0)
#define PONG                ((sf::Uint16) 1)
#define CLIENT_INPUT        ((sf::Uint16) 2)
#define CONNECTION_REQUEST  ((sf::Uint16) 3)
#define CONNECTION_RESPONSE ((sf::Uint16) 4)

#endif
