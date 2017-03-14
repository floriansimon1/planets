#ifndef TAIL_HPP
#define TAIL_HPP

#include "./skip.hpp"

template <typename Type>
CollectionWindow<Type> tail(CollectionWindow<Type> &window) {
    return skip(1, window);
}

#endif
