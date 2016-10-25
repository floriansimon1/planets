#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "../core/world.hpp"

struct Renderer {
    bool exit;

    Renderer(sf::RenderWindow &window);

    void render(World&);

    sf::Vector2f projectObjectCoordinates(sf::Vector2f&);

    private:
        sf::RenderWindow &window;
};

#endif
