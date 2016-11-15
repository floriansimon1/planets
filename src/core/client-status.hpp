#ifndef CLIENT_STATUS_HPP
#define CLIENT_STATUS_HPP

#include <SFML/System.hpp>

typedef sf::Uint16 ClientStatus;

#define SEARCHING  ((sf::Uint16) 0)
#define CONNECTING ((sf::Uint16) 1)
#define PINGING    ((sf::Uint16) 2)
#define EXIT       ((sf::Uint16) 3)

#endif
