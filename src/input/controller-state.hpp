#ifndef CONTROLLER_STATE_HPP
#define CONTROLLER_STATE_HPP

#include <SFML/System.hpp>

#include "./controller.hpp"

struct ControllerState: Controller {
    sf::Int32 timestamp;

    bool backward;
    bool forward;
    bool right;
    bool left;

    virtual bool accelerateBackward() const { return backward; }
    virtual bool accelerate() const         { return forward;  }
    virtual bool turnRight() const          { return right;    }
    virtual bool turnLeft() const           { return left;     }

    // Creates a state where no button is pressed with the given timestamp.
    static ControllerState initial(sf::Int32 timestamp);

    // Creates a controller state with no held buttons.
    ControllerState();
    ControllerState(sf::Int32 timestamp);
    ControllerState(const ControllerState &state);
    ControllerState(sf::Int32 t, const Controller &controller);
};

#endif
