#include "./get-current-tick-handler.hpp"
#include "../../network/communicator.hpp"
#include "../../network/network.hpp"
#include "../messages/pong.hpp"
#include "../server-state.hpp"

void GetCurrentTickHandler::handle(Communicator &communicator, Message &message, AgentState &statePointer) const {
    const auto &state = ((ServerState&) statePointer);

    Id requestId;

    packetRead(message.packet, requestId);

    Pong pong(message.host, requestId, state.world.worldClock);

    std::cout << ">> Received a ping" << std::endl;

    communicator.send(pong);
}
