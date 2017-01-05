#include "./server-state.hpp"

void ServerState::process(Application &application) {
    doProcess(static_cast<ServerApplication&>(application));
}
