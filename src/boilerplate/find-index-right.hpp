#ifndef FIND_INDEX_RIGHT_HPP
#define FIND_INDEX_RIGHT_HPP

#include <algorithm>

// Looks for a value satisfying the passed predicate by iterating in reverse order.
template<typename Collection, typename Iteratee>
auto findIndexRight(const Iteratee &predicate, Collection &collection) -> decltype(collection.begin()) {
    auto reverseIterator = std::find_if(
        collection.rbegin(),
        collection.rend(),

        [&predicate] (auto &value) {
            return predicate(value);
        }
    );

    if (reverseIterator == collection.rend()) {
        return collection.end();
    } else {
        return std::next(reverseIterator.base());
    }
}

#endif
