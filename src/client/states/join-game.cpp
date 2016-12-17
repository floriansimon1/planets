#include <iostream>

#include "./join-game.hpp"
#include "./synchronize-clocks.hpp"
#include "../messages/join-game-message.hpp"

#define assertConnectionResponseExpectedOrReturn(step) \
    if (!(step).isConnectionState()) { \
        std::cout \
        << ">> ERROR: connection response received for a request we did not make" \
        << std::endl; \
\
        return; \
    }

JoinGame::JoinGame(Host &g): game(g) {
}

void JoinGame::doProcess(ClientApplication &application) {
    // We must send the join request only once.
    if (requestSent) return;

    JoinGameMessage request(game, application.localPlayerName, communicator.socket.getLocalPort());

    application.communicator.send(request);

    requestSent = true;
}

bool JoinGame::isConnectionState() {
    return true;
}

void JoinGame::onConnection(ClientApplication &application) {
    const auto &currentStep = application.getCurrentStep();

    assertConnectionResponseExpectedOrReturn(currentStep);

    // Time to synchronize clocks!
    application.replaceCurrentStep(SynchronizeClocks(game));
}

void JoinGame::onConnectionRefused(ClientApplication &application) {
    const auto &currentStep = application.getCurrentStep();

    assertConnectionResponseExpectedOrReturn(currentStep);

    // Goes back to the "searching games" state.
    application.finishStep();
}
