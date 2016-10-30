#ifndef WORLD_SPACE_HPP
#define WORLD_SPACE_HPP

#include <SFML/Graphics.hpp>

struct WorldSpace {
    const sf::Vector2f offset;

    WorldSpace(const sf::Vector2f &o): offset(o) {}

    // Allows pass by copy.
    template <class Shape> void draw(sf::RenderTarget &target, Shape shape) const {
        shape.setPosition(shape.getPosition() + offset);

        target.draw(shape);
    }
};

#endif
