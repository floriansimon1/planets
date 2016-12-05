#ifndef REPEAT_N_HPP
#define REPEAT_N_HPP

#include <vector>
#include <functional>

inline void repeatN(unsigned int max, const std::function<void ()> &iteratee) {
    for (unsigned int it = 0; it < max; it++) {
        iteratee();
    }
}

#endif
