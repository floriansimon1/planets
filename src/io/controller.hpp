#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "../core/player.hpp"

// Controller in the "gamepad" sense.
struct Controller {
    std::shared_ptr<Player> player;

    Controller(std::shared_ptr<Player> p): player(p) {}

    bool turnRight() const;
    bool turnLeft() const;
};

#endif
