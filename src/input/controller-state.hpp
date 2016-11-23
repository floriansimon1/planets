#ifndef CONTROLLER_STATE_HPP
#define CONTROLLER_STATE_HPP

#include <SFML/System.hpp>

#include "./controller.hpp"

struct ControllerState: Controller {
    sf::Int32 timestamp;

    const bool backward;
    const bool forward;
    const bool right;
    const bool left;

    virtual bool accelerateBackward() const { return backward; }
    virtual bool accelerate() const         { return forward;  }
    virtual bool turnRight() const          { return right;    }
    virtual bool turnLeft() const           { return left;     }

    ControllerState(sf::Int32 t, const Controller &controller);

    // Assignment operator returns a copy so that it can be stored in vectors.
    ControllerState operator=(const ControllerState &c) const;
};

#endif
