#ifndef TAKE_UNTIL_HPP
#define TAKE_UNTIL_HPP

#include "./collection-window.hpp"

// Erases n head elements in place.
template <typename Collection, typename Iteratee>
CollectionWindow<Collection> takeUntil(
    Iteratee predicate,
    CollectionWindow<Collection> window
) {
    if (window.empty()) {
        return;
    }

    auto &start = window.begin();
    auto &end   = start;

    auto &it  = start;
    auto &max = std::next(window.last());

    for (it; it != max; it++) {
        if (predicate(*it)) {
            if (it == start) {
                return window.makeEmptyWindow();
            } else {
                return CollectionWindow<Collection>(window.collection, start, end);
            }
        }

        end = it;
    }

    // No element was removed.
    return window;
}

#endif
