#include <algorithm>

#include "./input-history-bookmark.hpp"

InputHistoryBookmark::InputHistoryBookmark(InputHistory &h): inputHistory(h) {
}

void InputHistoryBookmark::mark(sf::Int32 timestamp) {
    const auto newIterator = std::next(std::find_if(
        inputHistory.history.begin(),
        inputHistory.history.end(),

        [timestamp] (const auto &controllerState) {
            return controllerState.timestamp < timestamp;
        }
    ));

    Bookmark b { timestamp, newIterator };

    bookmark.emplace(b);
}
