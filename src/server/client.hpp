#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/System.hpp>
#include <experimental/optional>

#include "../core/player.hpp"
#include "../network/host.hpp"

struct Client: Player {
    sf::Int32 lastRecordedTimestamp;
    Host      host;

    bool validateTimestamp(sf::Int32 timestamp) const;
};

#endif
