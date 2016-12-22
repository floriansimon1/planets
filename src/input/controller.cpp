#include "./controller.hpp"

Controller Controller::inertPlayerControllerState() {
    // Trivial, I know, but it serves a semantical purpose...
    return Controller();
}

bool Controller::operator!=(const Controller &controller) const {
    return !(
        controller.turnLeft() == turnLeft()
        && controller.turnRight() == turnRight()
        && controller.accelerate() == accelerate()
        && controller.accelerateBackward() == accelerateBackward()
    );
}
