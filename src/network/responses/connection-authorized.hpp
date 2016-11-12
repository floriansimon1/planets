#ifndef CONNECTION_AUTHORIZED_HPP
#define CONNECTION_AUTHORIZED_HPP

#include "../response.hpp"

struct ConnectionAuthorized: Response {
    virtual void specializedResponsePreparation(sf::Packet&);
};

#endif
