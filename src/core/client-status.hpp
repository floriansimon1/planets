#ifndef CLIENT_STATUS_HPP
#define CLIENT_STATUS_HPP

#include <SFML/System.hpp>

typedef sf::Uint16 ClientStatus;

#define CONNECTING ((sf::Uint16) 0)
#define SEARCHING  ((sf::Uint16) 1)
#define PLAYING    ((sf::Uint16) 2)
#define SYNC       ((sf::Uint16) 3)
#define EXIT       ((sf::Uint16) 4)

#endif
