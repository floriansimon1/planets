#include <algorithm>

#include "./world.hpp"

#include "../math/vector2.hpp"

World::World(): dimensions(300.f, 300.f) {
    Player player;

    player.name = "Peter";

    players.push_back(player);
}

void World::makeNextFrame(std::vector<Controller> &controllers) {
    const auto elapsedTime = frameClock.getElapsedTime();

    std::for_each(
        controllers.begin(),
        controllers.end(),

        [&elapsedTime, this] (Controller &controller) {
            auto &player = players[controller.playerIndex];

            player.yaw = player.computeNewYaw(
                elapsedTime,
                controller.turnLeft(),
                controller.turnRight()
            );

            player.inertia = player.computeNewInertia(
                elapsedTime,
                controller.accelerate(),
                controller.accelerateBackward(),
                player.inertia,
                player.yaw
            );

            player.position = player.computeNewPosition(
                elapsedTime,
                player.position,
                player.inertia,
                dimensions
            );
        }
    );

    frameClock.restart();
}
