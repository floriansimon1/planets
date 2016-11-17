#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../core/player.hpp"
#include "../network/host.hpp"

struct Client: Player {
    Host host;
};

#endif
