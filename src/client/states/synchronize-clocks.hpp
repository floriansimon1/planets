#ifndef SYNCHRONIZE_CLOCKS_HPP
#define SYNCHRONIZE_CLOCKS_HPP

#include <vector>
#include <SFML/System.hpp>
#include <experimental/optional>

#include "./client-state.hpp"
#include "../network/network.hpp"
#include "../client-application.hpp"

struct SynchronizeClocks: ClientState {
    std::experimental::optional<Id>        currentlyExpectedPingRequestId;
    sf::Int32                              serverClockOffset;
    std::vector<sf::Int32>                 latencySamples;
    Timer                                  pingTimer;
    std::experimental::optional<sf::Int32> latency;
    Host                                   game;

    SynchronizeClocks(Host &game);

    Id reserveNextPingRequestId();
    bool pushLatencySamples();
    void averageLatency();

    virtual void doProcess(ClientApplication &application);
    virtual void onPong(ClientApplication &application, Id pongId, sf::Int32 serverClockOffset);

    private:
        bool enoughLatencySamples();
};

#endif
