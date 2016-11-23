#include "./controller.hpp"

bool Controller::operator!=(const Controller &controller) const {
    return !(
        controller.turnLeft() == turnLeft()
        && controller.turnRight() == turnRight()
        && controller.accelerate() == accelerate()
        && controller.accelerateBackward() == accelerateBackward()
    );
}

bool Controller::anyButtonHeld() const {
    return (
        turnLeft() || turnRight() || accelerate() || accelerateBackward()
    );
}
