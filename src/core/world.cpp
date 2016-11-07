#include <algorithm>
#include <iostream>

#include "./world.hpp"

#include "../math/vector2.hpp"

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

            controller->player->inertia = controller->player->computeNewInertia(
                elapsedTime,
                controller->accelerate(),
                controller->accelerateBackward(),
                controller->player->inertia,
                controller->player->yaw
            );

            std::cout
            << "("
            << controller->player->position.x
            << ", "
            << controller->player->position.y
            << ")"
            << std::endl;

            controller->player->position = controller->player->computeNewPosition(
                elapsedTime,
                controller->player->position,
                controller->player->inertia,
                dimensions
            );
        }
    );

    frameClock.restart();
}
