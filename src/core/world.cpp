#include <algorithm>

#include "./world.hpp"

#include "../math/vector2.hpp"

World::World(): dimensions(300.f, 300.f) {
    Player player;

    player.name = "Peter";

    players.push_back(player);
}

void World::makeNextFrame(sf::Int32 elapsedTime, const std::vector<ControllerState> &controllers) {
    for (size_t it = 0; it < players.size(); it++) {
        auto &player     = players[it];
        auto &controller = controllers[it];

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
}
