#ifndef PHYSICAL_PARAMETERS_HPP
#define PHYSICAL_PARAMETERS_HPP

#include <chrono>
#include <SFML/System.hpp>

#include "./movement.hpp"
#include "../boilerplate/optional.hpp"

// Angles are expressed in radians.
struct PhysicalParameters {
    // State variables.
    float        angle    = 0.f;
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f speed    = sf::Vector2f(0.f, 0.f);

    // Nominal values.
    float thrust   = 0.f;
    float rotation = 0.f;

    Optional<float> speedCap;

    void refresh(const Movement &movement, std::chrono::milliseconds dt);
};

#endif
