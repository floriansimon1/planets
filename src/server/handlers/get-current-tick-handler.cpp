#include "./get-current-tick-handler.hpp"
#include "../messages/pong.hpp"
#include "../server-state.hpp"

void GetCurrentTickHandler::handle(Communicator *communicator, Message &message, AgentState *statePointer) const {
    const auto &state = *((ServerState*) statePointer);

    Pong pong(message.host, state.world.worldClock);

    communicator->send(pong);
}
