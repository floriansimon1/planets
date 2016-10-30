#ifndef CORE_H
#define CORE_H

#include <SFML/System.hpp>
#include <memory>
#include <vector>

#include "./player.hpp"

struct World {
    // The first player in that list is the player controlled locally.
    std::vector<std::shared_ptr<Player>> players;

    sf::Vector2f dimensions;

    World(): dimensions(1000, 1000), players() {
        players.push_back(std::shared_ptr<Player>(new Player()));
    }

    private:
        World(World&);
};

#endif
