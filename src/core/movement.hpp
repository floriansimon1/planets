#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "../boilerplate/optional.hpp"

struct Movement {
    enum Rotation { left,       right      };
    enum Thrust   { accelerate, decelerate };

    const Optional<Rotation> rotationMovement;
    const Optional<Thrust>   thrustMovement;

    Movement(Rotation rotation, Thrust thrust): rotationMovement(rotation), thrustMovement(thrust) {}
    Movement(Rotation rotation):                rotationMovement(rotation)                         {}
    Movement(Thrust thrust):                    thrustMovement(thrust)                             {}
};

#endif
