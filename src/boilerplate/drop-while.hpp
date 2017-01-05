#ifndef DROP_WHILE_HPP
#define DROP_WHILE_HPP

// Erases n head elements in place.
template <typename Collection, typename Iteratee>
void dropWhile(Collection &collection, Iteratee predicate) {
    if (collection.empty()) {
        return;
    }

    auto &start = collection.begin();
    auto &end   = start;

    for (auto &it = start; it != collection.end(); it++) {
        if (!predicate(*it)) {
            break;
        }

        end = it;
    }

    collection.erase(start, end);
}

#endif
