#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/System.hpp>
#include <experimental/optional>

#include "../core/player.hpp"
#include "../network/host.hpp"
#include "../input/input-history.hpp"

struct Client {
    Player player;
    Host   host;

    void bufferControllerState(const ControllerState &state);
};

#endif
