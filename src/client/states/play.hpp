#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/System.hpp>
#include <string>

#include "../../core/world.hpp"
#include "../../input/gamepad.hpp"
#include "./synchronize-clocks.hpp"
#include "../../network/network.hpp"
#include "../local-input-history.hpp"
#include "../../input/controller-state.hpp"

struct Play: ClientState {
    sf::Int32         serverClockOffset;
    LocalInputHistory inputHistory;
    World             serverWorld;
    sf::Int32         latency;
    Gamepad           gamepad;
    World             world;
    Host              game;
    std::string       name;

    sf::Int32 getServerTimestamp() const;

    Play(const Host &game, sf::Int32 latency, sf::Int32 serverClockOffset);

    virtual void doProcess(ClientApplication &application);
    virtual bool isGameState() const;

    private:
        void processInputHistory(Id from);
};

#endif
