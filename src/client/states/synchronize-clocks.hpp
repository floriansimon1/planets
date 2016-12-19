#ifndef SYNCHRONIZE_CLOCKS_HPP
#define SYNCHRONIZE_CLOCKS_HPP

#include <vector>
#include <SFML/System.hpp>
#include <experimental/optional>

#include "./client-state.hpp"
#include "../../core/timer.hpp"
#include "../client-application.hpp"
#include "../../network/network.hpp"

struct SynchronizeClocks: ClientState {
    std::experimental::optional<Id> currentlyExpectedPingRequestId;
    std::vector<sf::Int32>          latencySamples;
    Timer                           pingTimer;
    Host                            game;

    SynchronizeClocks(const Host &game);

    Id reserveNextPingRequestId();
    bool pushLatencySamples();
    sf::Int32 averageLatency();

    virtual void doProcess(ClientApplication &application);
    virtual void onPong(ClientApplication &application, Id pongId, sf::Int32 serverClockOffset);

    private:
        bool enoughLatencySamples();
};

#endif
