#include "./client.hpp"

void Client::bufferControllerState(const ControllerState &state) {
    const auto &firstEntry = *player.inputHistory.history.begin();

    /*
    * For laggy/cheating players, we ignore antidated controller states.
    * In that case, we replace the first state in the buffer history with
    * what we've received from the client, but with a corrected timestamp.
    * Otherwise, we just push the input inside the history.
    */
    if (firstEntry.timestamp < state.timestamp) {
        player.inputHistory.history.pop_front();

        player.inputHistory.history.push_front(ControllerState(firstEntry.timestamp, state));
    } else {
        player.inputHistory.insertControllerState(state);
    }
}
