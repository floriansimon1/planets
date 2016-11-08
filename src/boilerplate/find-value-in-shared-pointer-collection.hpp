#ifndef FIND_VALUE_IN_POINTER_COLLECTION_HPP
#define FIND_VALUE_IN_POINTER_COLLECTION_HPP

#include <algorithm>
#include <memory>

template <class Collection, class Object>
std::shared_ptr<Object>
findValueInSharedPointerCollection(const Collection &collection, const Object &object) {
    const auto collectionEnd = collection.end();

    const auto found = std::find_if(collection.begin(), collectionEnd, [&object] (const auto pointer) {
        return *pointer == object;
    });

    if (found == collectionEnd) {
        return nullptr;
    } else {
        return *found;
    }
}

#endif
