#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../core/player.hpp"

// Controller in the "gamepad" sense.
struct Controller {
    virtual bool accelerateBackward() const { return false; }
    virtual bool accelerate() const         { return false; }
    virtual bool turnRight() const          { return false; }
    virtual bool turnLeft() const           { return false; }

    bool operator!=(const Controller &c) const;

    static Controller inertPlayerControllerState();
};

#endif
