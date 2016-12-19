#ifndef PLAYER_INPUT_HPP
#define PLAYER_INPUT_HPP

#include <SFML/System.hpp>
#include <deque>

#include "../../input/controller-state.hpp"
#include "../../network/outgoing-message.hpp"

struct PlayerInput: OutgoingMessage {
    PlayerInput(const Host &h, const std::deque<std::vector<ControllerState>> &inputs);

    virtual void prepare();

    private:
        std::deque<std::vector<ControllerState>> inputs;
};

#endif
