#include "./input-history.hpp"
#include "../boilerplate/drop-while.hpp"
#include "../boilerplate/insert-where.hpp"

void InputHistory::bufferInput(sf::Int32 timestamp, const Controller &controller) {
    // We buffer controller states only if the last that we have is different from the current one.
    if (history.size() && controller != history.back()) {
        history.push_back(ControllerState(timestamp, controller));
    }
}

void InputHistory::discardHistory(sf::Int32 timestamp) {
    dropWhile(history, [timestamp] (const auto &state) {
        return timestamp < state.timestamp;
    });
}

void InputHistory::insertControllerState(const ControllerState &state) {
    insertWhere(history, state, [&state] (const auto &entry) {
        return entry.timestamp > state.timestamp;
    });
}
