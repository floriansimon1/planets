#include "./input-history-transfer-bookmark.hpp"

InputHistoryTransferBookmark::InputHistoryTransferBookmark(InputHistory &h):
    InputHistoryBookmark(h)
{
}

bool InputHistoryTransferBookmark::shouldSend(sf::Int32 timestamp) const {
    if (inputHistory.history.empty() || !bookmark) {
        return true;
    }

    const auto &lastSendInfo = bookmark.value();

    const auto dt = timestamp - lastSendInfo.timestamp;

    // Advance the last send input by as many ticks as needed, and returns true.
    if (dt >= TICK_DELAY) {
        return true;
    } else {
        return false;
    }
}

std::list<ControllerState> InputHistoryTransferBookmark::getHistoryToSend() const {
    if (!bookmark) {
        return inputHistory.history;
    }

    const auto &lastSendInfo = bookmark.value();

    return std::list<ControllerState>(
        std::next(lastSendInfo.iterator),
        inputHistory.history.end()
    );
}
