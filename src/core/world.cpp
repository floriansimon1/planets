#include <algorithm>

#include "./world.hpp"

#include "../math/vector2.hpp"

World::World(): dimensions(300.f, 300.f) {
    Player *player = new Player();

    player->name = "Peter";

    players.push_back(std::shared_ptr<Player>(player));
}

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
