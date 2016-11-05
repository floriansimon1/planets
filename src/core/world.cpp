#include "world.hpp"

#include <algorithm>

void World::makeNextFrame(std::vector<Controller*> &controllers) {
    const auto elapsedTime = frameClock.getElapsedTime();

    std::for_each(
        controllers.begin(),
        controllers.end(),

        [&elapsedTime, this] (Controller *controller) {
            const auto yawChangeMultiplier = (
                (controller->turnLeft() ? -1.f : 0.f)
                + (controller->turnRight() ? 1.f : 0.f)
            );

            if (yawChangeMultiplier) {
                const auto absoluteYawChange = (
                    elapsedTime.asMilliseconds()
                    * (yawChangeSpeed / 1000.f)
                );

                controller->player->yaw += absoluteYawChange * yawChangeMultiplier;
            }
        }
    );

    frameClock.restart();
}
