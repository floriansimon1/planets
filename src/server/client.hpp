#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/System.hpp>
#include <experimental/optional>

#include "../core/player.hpp"
#include "../network/host.hpp"

struct Client: Player {
    std::experimental::optional<sf::Int32> lastRecordedTimestamp;
    Host                                   host;

    std::experimental::optional<sf::Int32> validateTimestamp(sf::Int32 timestamp) const;
};

#endif
