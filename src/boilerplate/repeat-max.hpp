#ifndef REPEAT_MAX_HPP
#define REPEAT_MAX_HPP

#include <vector>
#include <functional>

struct InterruptRepeatMaxException {};

// If the return value of the iteratee is true, then the repetition is stopped.
template <typename OutputType>
std::vector<OutputType>
repeatMax(unsigned int max, const std::function<OutputType()> &iteratee) {
    std::vector<OutputType> results;

    for (unsigned int it = 0; it < max; it++) {
        try {
            OutputType result = iteratee();

            results.push_back(result);
        } catch (InterruptRepeatMaxException&) {
            break;
        }
    }

    return results;
}

#endif
