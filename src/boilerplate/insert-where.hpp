#ifndef INSERT_WHERE_HPP
#define INSERT_WHERE_HPP

#include <algorithm>

// This does work with empty collections too.
template<typename Collection, typename Iteratee, typename Value>
void insertWhere(Collection &collection, Value value, Iteratee predicate) {
    auto insertionPoint = std::find_if(collection.begin(), collection.end(), predicate);

    collection.insert(insertionPoint, value);
}

#endif
