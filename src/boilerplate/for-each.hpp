#ifndef FOR_EACH_HPP
#define FOR_EACH_HPP

#include <algorithm>

#include "./collection-window.hpp"

template <typename Collection, typename Iteratee>
void forEach(const Iteratee &iteratee, Collection &collection) {
    unsigned i = 0;

    std::for_each(collection.begin(), collection.end(), [&iteratee, &i] (auto &value) {
        iteratee(value, i);

        i++;
    });
}

template <typename Type, typename Iteratee>
void forEach(const Iteratee &iteratee, CollectionWindow<Type> window) {
    unsigned i = 0;

    std::for_each(window.begin(), std::next(window.last()), [&iteratee, &i] (auto &value) {
        iteratee(value, i);

        i++;
    });
}

#endif
