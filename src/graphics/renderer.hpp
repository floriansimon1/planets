#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "./world-space.hpp"
#include "../client/client-application.hpp"

struct Renderer {
    Renderer(sf::RenderWindow &window);

    void render(const ClientApplication &application) const;

    private:
        sf::RenderWindow &window;
};

#endif
