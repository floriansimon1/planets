#include "./pong-handler.hpp"
#include "../../network/network.hpp"
#include "../states/client-state.hpp"
#include "../messages/get-current-tick-request.hpp"

void PongHandler::doHandle(ClientApplication &application, Message &message) const {
    auto &currentStep = dynamic_cast<ClientState&>(application.getCurrentStep());

    Id        pongId;
    sf::Int32 serverClockOffset;

    packetRead(message.packet, pongId);
    packetRead(message.packet, serverClockOffset);

    currentStep.onPong(application, pongId, serverClockOffset);
};
