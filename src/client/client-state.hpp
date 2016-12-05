#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <experimental/optional>
#include <string>
#include <vector>
#include <deque>

#include "../core/world.hpp"
#include "../core/timer.hpp"
#include "./input-history.hpp"
#include "../network/host.hpp"
#include "../input/gamepad.hpp"
#include "../network/network.hpp"
#include "../core/agent-state.hpp"
#include "../core/client-status.hpp"
#include "../input/controller-state.hpp"

struct ClientState: AgentState {
    ClientStatus status = SEARCHING;

    std::experimental::optional<Id>          currentlyExpectedPingRequestId;
    sf::Int32                                serverClockOffset;
    std::vector<sf::Int32>                   latencySamples;
    std::vector<Host>                        availableGames;
    InputHistory                             inputHistory;
    World                                    serverWorld;
    Timer                                    pingTimer;
    std::experimental::optional<sf::Int32>   latency;
    Gamepad                                  gamepad;
    World                                    world;
    std::experimental::optional<Host>        game;
    std::string                              name;

    sf::Int32 getServerTimestamp() const;
    Id reserveNextPingRequestId();
    bool pushLatencySamples();
    void averageLatency();

    // Advances the game simulation.
    void process();

    private:
        void processInputHistory(Id from);
};

#endif
