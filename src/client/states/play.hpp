#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/System.hpp>
#include <string>

#include "../../core/world.hpp"
#include "../input-history.hpp"
#include "../../input/gamepad.hpp"
#include "./synchronize-clocks.hpp"
#include "../../network/network.hpp"
#include "../../input/controller-state.hpp"

struct Play: ClientState {
    InputHistory inputHistory;
    World        serverWorld;
    Gamepad      gamepad;
    World        world;
    Host         game;
    std::string  name;

    sf::Int32 getServerTimestamp() const;

    Play(SynchronizeClocks &state);

    virtual void doProcess(ClientApplication &application);

    private:
        void processInputHistory(Id from);
};

#endif
