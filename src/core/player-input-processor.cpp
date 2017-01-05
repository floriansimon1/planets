#include "./player-input-processor.hpp"
#include "../math/vector2.hpp"

std::vector<Player> PlayerInputProcessor::process(
    sf::Int32 elapsedTime,
    const World &world,
    std::vector<PlayerInput> &playerInputs
) {
    std::vector<Player> newPlayerStates;

    std::transform(
        playerInputs.begin(),
        playerInputs.end(),
        newPlayerStates.begin(),

        [&world, elapsedTime] (const auto &playerInput) {
            Player          player     = playerInput.player;
            ControllerState controller = playerInput.input;

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
                world.dimensions
            );
        }
    );

    return newPlayerStates;
}
