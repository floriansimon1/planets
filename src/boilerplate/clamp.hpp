#ifndef CLAMP_HPP
#define CLAMP_HPP

template <typename Type>
Type clamp(const Type &value, const Type &low, const Type &high) {
    if (value < low) {
        return low;
    }

    if (high < value) {
        return high;
    }

    return value;
}

#endif
