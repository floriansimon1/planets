#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <experimental/optional>
#include <string>
#include <vector>
#include <deque>

#include "../core/world.hpp"
#include "../core/timer.hpp"
#include "../network/host.hpp"
#include "../network/network.hpp"
#include "../core/agent-state.hpp"
#include "../input/controller.hpp"
#include "../core/client-status.hpp"
#include "../input/controller-state.hpp"

struct ClientState: AgentState {
    // In ms.
    const sf::Int32 tickDelay = 20;

    sf::Int32    lastInputSend = 0;
    ClientStatus status        = SEARCHING;

    std::experimental::optional<Id>          currentlyExpectedPingRequestId;
    std::deque<std::vector<ControllerState>> bufferedControllerStates;
    sf::Int32                                serverClockOffset;
    std::vector<sf::Int32>                   latencySamples;
    std::vector<Host>                        availableGames;
    std::vector<Controller>                  controllers;
    Timer                                    pingTimer;
    std::experimental::optional<sf::Int32>   latency;
    World                                    world;
    std::experimental::optional<Host>        game;
    std::string                              name;

    ControllerState bufferLocalPlayerInput();
    sf::Int32 getServerTimestamp() const;
    Id reserveNextPingRequestId();
    bool shouldSendPlayerInput();
    void clearBufferedInputs();
    bool pushLatencySamples();
    void averageLatency();

    // Advances the game simulation.
    void refresh();
};

#endif
