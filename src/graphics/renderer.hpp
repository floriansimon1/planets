#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "./world-space.hpp"
#include "../core/world.hpp"

struct Renderer {
    Renderer(sf::RenderWindow &window);

    void render(const World&) const;

    private:
        sf::RenderWindow &window;
};

#endif
