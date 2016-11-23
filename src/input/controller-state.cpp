#include "./controller-state.hpp"

ControllerState::ControllerState(sf::Int32 t, const Controller &controller):
    timestamp(t),
    backward(controller.accelerateBackward()),
    forward(controller.accelerate()),
    right(controller.turnRight()),
    left(controller.turnLeft()) {
}

ControllerState ControllerState::operator=(const ControllerState &c) const {
    return ControllerState(c);
}
