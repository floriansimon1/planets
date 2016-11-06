#include "world.hpp"

#include <algorithm>

void World::makeNextFrame(std::vector<Controller*> &controllers) {
    const auto elapsedTime = frameClock.getElapsedTime();

    std::for_each(
        controllers.begin(),
        controllers.end(),

        [&elapsedTime, this] (Controller *controller) {
            controller->player->yaw = controller->player->computeNewYaw(
                elapsedTime,
                controller->turnLeft(),
                controller->turnRight()
            );

            controller->player->speed = controller->player->computeNewSpeed(
                elapsedTime,
                controller->accelerate(),
                controller->accelerateBackward()
            );
        }
    );

    frameClock.restart();
}
