#ifndef GAMEPAD_HPP
#define GAMEPAD_HPP

#include "./controller.hpp"

struct Gamepad: Controller {
    virtual bool accelerateBackward() const;
    virtual bool accelerate() const;
    virtual bool turnRight() const;
    virtual bool turnLeft() const;
};

#endif
