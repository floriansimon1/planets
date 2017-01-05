#ifndef IDS_GENERATOR_HPP
#define IDS_GENERATOR_HPP

#include "./id.hpp"

struct IdsGenerator {
    IdsGenerator(): current(0) {}

    Id generateId() {
        return ++current;
    }

    private:
        Id current;
};

#endif
