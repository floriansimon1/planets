#ifndef REMOVE_IN_HPP
#define REMOVE_IN_HPP

#include <algorithm>

template <class Iteratee, class Collection> void removeIn(Collection &collection, Iteratee iteratee) {
    const auto newEnd = std::remove_if(collection.begin(), collection.end(), iteratee);

    collection.erase(newEnd, collection.end());
}

#endif
