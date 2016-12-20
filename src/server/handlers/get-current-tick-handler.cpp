#include "./get-current-tick-handler.hpp"
#include "../../network/network.hpp"
#include "../states/serve-game.hpp"
#include "../messages/pong.hpp"

#include <iostream>

void GetCurrentTickHandler::doHandle(ServerApplication &application, Message &message) const {
    const auto &step = static_cast<ServeGame&>(*application.getCurrentStep());

    Id requestId;

    packetRead(message.packet, requestId);

    Pong pong(message.host, requestId, step.world.worldClock);

    std::cout << ">> Received a ping" << std::endl;

    application.communicator.send(pong);
}
