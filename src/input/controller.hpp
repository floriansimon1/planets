#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../core/player.hpp"

// Controller in the "gamepad" sense.
struct Controller {
    unsigned int playerIndex;

    Controller(unsigned int pi): playerIndex(pi) {}

    bool accelerateBackward() const;
    bool accelerate() const;
    bool turnRight() const;
    bool turnLeft() const;
};

#endif
