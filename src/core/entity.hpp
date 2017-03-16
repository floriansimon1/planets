#ifndef ENTITY_H
#define ENTITY_H

#include <chrono>

#include "./movement.hpp"
#include "./physical-parameters.hpp"

// Angles are expressed in radians, distances in abstract units.
struct Entity {
    const PhysicalParameters physicalParameters;

    Entity refresh(const Movement &movement, std::chrono::milliseconds dt) const;
};

#endif
