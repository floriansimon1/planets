#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/System.hpp>
#include <experimental/optional>

#include "../core/player.hpp"
#include "../network/host.hpp"
#include "../input/input-history.hpp"

struct Client: Player {
    InputHistory inputHistory;
    Host         host;

    bool validateTimestamp(sf::Int32 timestamp) const;

    void bufferControllerState(const ControllerState &state);
};

#endif
