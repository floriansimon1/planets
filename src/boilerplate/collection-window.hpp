#ifndef COLLECTION_WINDOW_HPP
#define COLLECTION_WINDOW_HPP

#include <iterator>

template <typename Collection>
struct CollectionWindow {
    using Iterator   = typename Collection::iterator;
    using WindowType = CollectionWindow<Collection>;

    Collection collection;
    Iterator   lastIterator;
    Iterator   beginIterator;

    CollectionWindow(Collection c): collection(c), beginIterator(c.end()), lastIterator(c.end()) {}

    CollectionWindow(Collection c, std::nullptr_t noBegin, Iterator last):
        collection(c),
        lastIterator(last),
        beginIterator(c.begin())
    {
    }

    CollectionWindow(Collection c, Iterator begin, std::nullptr_t noLast):
        collection(c),
        lastIterator(std::prev(c.end())),
        beginIterator(begin)
    {
    }

    CollectionWindow(Collection c, Iterator begin, Iterator end):
        collection(c),
        lastIterator(end),
        beginIterator(begin)
    {
    }

    CollectionWindow(const CollectionWindow &window):
        collection(window.collection),
        lastIterator(window.lastIterator),
        beginIterator(window.beginIterator)
    {
    }

    WindowType makeEmptyWindow() const {
        return WindowType(collection);
    }

    Iterator end() {
        return collection.end();
    }

    bool empty() {
        return beginIterator == end();
    }

    Iterator begin() {
        return beginIterator;
    }

    Iterator last() {
        return lastIterator;
    }
};

#endif
