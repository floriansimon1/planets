#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <experimental/optional>
#include <string>
#include <vector>

#include "../core/world.hpp"
#include "../core/timer.hpp"
#include "../network/host.hpp"
#include "../network/network.hpp"
#include "../core/agent-state.hpp"
#include "../core/client-status.hpp"

struct ClientState: AgentState {
    ClientStatus status = SEARCHING;

    std::experimental::optional<Id>        currentlyExpectedPingRequestId;
    sf::Int32                              serverClockOffset;
    std::vector<sf::Int32>                 latencySamples;
    std::vector<Host>                      availableGames;
    Timer                                  pingTimer;
    std::experimental::optional<sf::Int32> latency;
    World                                  world;
    std::experimental::optional<Host>      game;
    std::string                            name;

    Id reserveNextPingRequestId();
    bool pushLatencySamples();
    void averageLatency();
};

#endif
