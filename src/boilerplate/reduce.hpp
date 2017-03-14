#ifndef REDUCE_HPP
#define REDUCE_HPP

#include <iterator>
#include <numeric>

template <typename CollectionWindow, typename Iteratee, typename ReturnType>
ReturnType reduce(const Iteratee &iteratee, ReturnType init, CollectionWindow collectionWindow) {
    return std::accumulate(
        collectionWindow.begin(),
        std::next(collectionWindow.last()),
        init,
        iteratee
    );
}

#endif
