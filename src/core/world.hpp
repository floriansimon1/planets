#ifndef CORE_H
#define CORE_H

#include <SFML/System.hpp>
#include <memory>
#include <vector>

#include "./player.hpp"
#include "../io/controller.hpp"

struct World {
    sf::Clock    frameClock;
    sf::Vector2f dimensions;

    // The first player in that list is the player controlled locally.
    std::vector<std::shared_ptr<Player>> players;

    World(): dimensions(1000, 1000), players() {
        players.push_back(std::shared_ptr<Player>(new Player()));
    }

    void makeNextFrame(std::vector<Controller*>&);

    private:
        World(World&);
};

#endif
