#include "./client-state.hpp"

void ClientState::process(Application &application) {
    doProcess(dynamic_cast<ClientApplication&>(application));
}

bool ClientState::isConnectionState() {
    return false;
}
