#include "./local-input-history.hpp"

void LocalInputHistory::beforeBufferingStarts(sf::Int32 timestamp) {
    lastSent     = 0;
    lastSentTime = timestamp;
}

bool LocalInputHistory::shouldSend(sf::Int32 timestamp) {
    const auto difference = timestamp - getStateIterator(lastSent)->timestamp;

    // Advance the last send input by as many ticks as needed, and returns true.
    if (difference >= TICK_DELAY) {
        return true;
    } else {
        return false;
    }
}

void LocalInputHistory::historySent(sf::Int32 timestamp) {
    lastSentTime = timestamp;
    lastSent     = history.size();
}
