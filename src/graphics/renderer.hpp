#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "../core/world.hpp"

struct Renderer {;
    bool exit;

    Renderer(sf::RenderWindow &window);

    void render(World&);

    private:
        sf::RenderWindow &window;
};

#endif
