#include "./input-history.hpp"
#include "../boilerplate/drop.hpp"

// Implementation note: we should always have at least two entries in the history.

void InputHistory::startBuffering(sf::Int32 timestamp, const Controller &initial) {
    lastDisplayed = 0;
    lastDiscarded = 0;

    if (history.empty()) {
        bufferInput(timestamp, initial);
    } else {
        drop(history, history.size() - 1);
    }
}

void InputHistory::bufferInput(sf::Int32 timestamp, const Controller &controller) {
    history.push_back(ControllerState(timestamp, controller));
}

const ControllerState& InputHistory::operator[](Id stateId) {
    return *getStateIterator(stateId);
}

std::vector<ControllerState>::iterator InputHistory::getStateIterator(Id stateId) {
    return history.begin() + (stateId - lastDiscarded);
}

void InputHistory::historyDisplayed() {
    lastDisplayed = history.size() - 1;
}

void InputHistory::discardUpTo(Id upToId) {
    drop(history, upToId - lastDiscarded);

    lastDiscarded = upToId;
}
