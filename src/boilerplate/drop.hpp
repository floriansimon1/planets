#ifndef DROP_HPP
#define DROP_HPP

// Erases n head elements in place.
template <typename Collection>
void drop(Collection &x, unsigned int n) {
    x.erase(x.begin(), x.begin() + n);
}

#endif
