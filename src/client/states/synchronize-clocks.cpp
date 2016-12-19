#include <iostream>
#include <numeric>

#include "./play.hpp"
#include "./synchronize-clocks.hpp"
#include "../messages/get-current-tick-request.hpp"

SynchronizeClocks::SynchronizeClocks(const Host &g): game(g) {
}

bool SynchronizeClocks::enoughLatencySamples() {
    return latencySamples.size() >= 4;
}

void SynchronizeClocks::doProcess(ClientApplication &application) {
    if (!currentlyExpectedPingRequestId) {
        std::cout << ">> Initiating game clock synchronization..." << std::endl;

        GetCurrentTickRequest request(game, reserveNextPingRequestId());

        application.communicator.send(request);
    }
}

void SynchronizeClocks::onPong(ClientApplication &application, Id pongId, sf::Int32 clockOffset) {
    if (currentlyExpectedPingRequestId && currentlyExpectedPingRequestId.value() == pongId) {
        sf::Int32 latency = pingTimer.stop().asMilliseconds() / 2;

        latencySamples.push_back(latency);

        if (enoughLatencySamples()) {
            currentlyExpectedPingRequestId = std::experimental::optional<Id>();

            averageLatency();

            std::cout
            << ">> Average latency: " << latency << " ms\n"
            << ">> Clock offset: " << clockOffset << " ms"
            << std::endl;

            application.replaceCurrentStep(std::make_shared<Play>(
                game, clockOffset, latency
            ));
        } else {
            GetCurrentTickRequest request(game, reserveNextPingRequestId());

            std::cout
            << ">> Sending ping request #"
            << currentlyExpectedPingRequestId.value()
            << "..."
            << std::endl;

            application.communicator.send(request);
        }
    }
}

Id SynchronizeClocks::reserveNextPingRequestId() {
    const Id value = 1 + currentlyExpectedPingRequestId.value_or(0);

    currentlyExpectedPingRequestId.emplace(value);

    pingTimer.start();

    return value;
}

sf::Int32 SynchronizeClocks::averageLatency() {
    sf::Int32 sum = std::accumulate(
        latencySamples.begin(),
        latencySamples.end(),
        0,

        [] (auto a, auto b) {
            return a + b;
        }
    );

    sf::Int32 average = sum / latencySamples.size();

    // Erase all samples but the first.
    latencySamples.erase(latencySamples.begin() + 1);

    // Set the first sample to the averaged value calculated above.
    latencySamples[0] = average;

    return average;
}
