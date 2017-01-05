#include "./controller-state.hpp"

ControllerState::ControllerState(): ControllerState(0) {
}

ControllerState::ControllerState(sf::Int32 t, const Controller &controller):
    timestamp(t),
    backward(controller.accelerateBackward()),
    forward(controller.accelerate()),
    right(controller.turnRight()),
    left(controller.turnLeft())
{
}

ControllerState::ControllerState(sf::Int32 t):
    timestamp(t),
    backward(false),
    forward(false),
    right(false),
    left(false)
{
}

ControllerState::ControllerState(const ControllerState &state):
    ControllerState(state.timestamp, state)
{
}

bool ControllerState::isForged() const {
    return false;
}
