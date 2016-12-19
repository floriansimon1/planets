#include "./client-state.hpp"

void ClientState::process(Application &application) {
    doProcess(static_cast<ClientApplication&>(application));
}

bool ClientState::isConnectionState() const {
    return false;
}

bool ClientState::isGameState() const {
    return false;
}
