#ifndef INPUT_HISTORY_TRANSFER_BOOKMARK_HPP
#define INPUT_HISTORY_TRANSFER_BOOKMARK_HPP

#include "./input-history-bookmark.hpp"

struct InputHistoryTransferBookmark: InputHistoryBookmark {
    bool shouldSend(sf::Int32 timestamp) const;
    std::list<ControllerState> getHistoryToSend() const;

    InputHistoryTransferBookmark(InputHistory &history);
};

#endif
