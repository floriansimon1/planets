#ifndef SKIP_HPP
#define SKIP_HPP

#include "./collection-window.hpp"

template <typename Type>
CollectionWindow<Type> skip(unsigned n, CollectionWindow<Type> window) {
    for (auto i = n; i > 0; i--) {
        window.beginIterator++;

        if (
            window.beginIterator == window.end()
            || (window.beginIterator == window.lastIterator && n > 0)
        ) {
            window.beginIterator = window.end();
            window.lastIterator  = window.end();

            break;
        }
    }

    return window;
}

#endif
