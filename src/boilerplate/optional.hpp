#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP

#include <experimental/optional>

// Simple workaround to make working with optionals less annoying.
template <typename Type>
struct Optional: std::experimental::optional<Type> {
    Optional(const Type &x): std::experimental::optional<const Type>(x) {}
    Optional(Type &x): std::experimental::optional<Type>(x) {}
    Optional() {}
};

#endif
