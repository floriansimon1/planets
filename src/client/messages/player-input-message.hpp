#ifndef PLAYER_INPUT_MESSAGE_HPP
#define PLAYER_INPUT_MESSAGE_HPP

#include <SFML/System.hpp>
#include <list>

#include "../../input/controller-state.hpp"
#include "../../network/outgoing-message.hpp"

struct PlayerInputMessage: OutgoingMessage {
    PlayerInputMessage(const Host &h, const std::list<ControllerState> &inputs);

    virtual void prepare();

    private:
        std::list<ControllerState> inputs;
};

#endif
