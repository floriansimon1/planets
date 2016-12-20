#include "./client-input-handler.hpp"
#include "../states/serve-game.hpp"

void ClientInputHandler::doHandle(ServerApplication &application, Message &message) const {
    const auto &step = static_cast<ServeGame&>(*application.getCurrentStep());
}
