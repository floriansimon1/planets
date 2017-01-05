#ifndef INPUT_HISTORY_BOOKMARK_HPP
#define INPUT_HISTORY_BOOKMARK_HPP

#include <experimental/optional>

#include "./input-history.hpp"

struct InputHistoryBookmark {
    struct Bookmark {
        sf::Int32                            timestamp;
        std::list<ControllerState>::iterator iterator;
    };

    std::experimental::optional<Bookmark> bookmark;
    InputHistory                          &inputHistory;

    InputHistoryBookmark(InputHistory &history);

    void mark(sf::Int32 timestamp);
};

#endif
