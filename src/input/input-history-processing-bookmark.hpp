#ifndef INPUT_HISTORY_PROCESSING_BOOKMARK_HPP
#define INPUT_HISTORY_PROCESSING_BOOKMARK_HPP

#include "./input-history-bookmark.hpp"

struct InputHistoryProcessingBookmark: InputHistoryBookmark {
    std::list<ControllerState> getHistoryToProcess(sf::Int32 timestamp) const;

    InputHistoryProcessingBookmark(InputHistory &history);
};

#endif
