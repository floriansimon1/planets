#include "./pong-handler.hpp"
#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../messages/get-current-tick-request.hpp"

void PongHandler::handle(ClientApplication &application, Message &message) const {
    const auto &currentStep = application.getCurrentStep();

    Id        pongId;
    sf::Int32 serverClockOffset;

    packetRead(message.packet, pongId);
    packetRead(message.packet, serverClockOffset);

    currentStep.onPong(application, pongId, serverClockOffset);
};
