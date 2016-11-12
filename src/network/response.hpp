#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <SFML/Network.hpp>

struct Response {
    sf::Packet prepare();

    protected:
        virtual void specializedResponsePreparation(sf::Packet&) = 0;
};

#endif
