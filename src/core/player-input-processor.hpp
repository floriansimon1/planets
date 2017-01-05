#ifndef PLAYER_INPUT_PROCESSOR
#define PLAYER_INPUT_PROCESSOR

#include <SFML/System.hpp>
#include <vector>

#include "../input/controller-state.hpp"
#include "./player.hpp"
#include "./world.hpp"

struct PlayerInput {
    ControllerState input;
    Player          player;
};

namespace PlayerInputProcessor {
    std::vector<Player> process(
        sf::Int32 elapsedTime,
        const World &world,
        std::vector<PlayerInput> &playerInputs
    );
};

#endif
