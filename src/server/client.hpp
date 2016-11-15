#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../core/client-status.hpp"
#include "../network/host.hpp"

struct Client: Host {
    Client(Host &h): Host(h) {}
};

#endif
