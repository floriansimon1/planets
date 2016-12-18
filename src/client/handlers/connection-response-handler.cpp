#include <iostream>

#include "../../network/network.hpp"
#include "../states/client-state.hpp"
#include "./connection-response-handler.hpp"

void ConnectionResponseHandler::doHandle(ClientApplication &application, Message &message) const {
    auto &currentStep = dynamic_cast<ClientState&>(application.getCurrentStep());

    bool authorized;

    packetRead(message.packet, authorized);

    if (authorized) {
        std::cout << ">> Request to join game granted" << std::endl;

        currentStep.onConnection(application);
    } else {
        std::cout << ">> Request to join game denied" << std::endl;

        currentStep.onConnectionRefused(application);
    }
}
