#ifndef CORE_H
#define CORE_H

#include <SFML/System.hpp>
#include <memory>
#include <vector>

#include "./player.hpp"
#include "../input/controller-state.hpp"

struct World {
    sf::Clock    worldClock;
    sf::Vector2f dimensions;

    // The first player in that list is the player controlled locally.
    std::vector<Player> players;

    World();

    void makeNextFrame(sf::Int32 elapsedTime, const std::vector<ControllerState> &controllers);

    private:
        World(World&);
};

#endif
