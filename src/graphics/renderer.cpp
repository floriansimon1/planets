#include "renderer.hpp"

#include <algorithm>

Renderer::Renderer(sf::RenderWindow &w): exit(false), window(w) {
    window.setFramerateLimit(60);
}

void Renderer::render(World &world) {
    window.clear();

    std::for_each(world.players.begin(), world.players.end(), [] (auto it) {
        
    });

    window.display();
}
