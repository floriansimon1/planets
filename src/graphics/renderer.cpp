#include "renderer.hpp"

#include <algorithm>

Renderer::Renderer(sf::RenderWindow &w): exit(false), window(w) {
    window.setFramerateLimit(60);
}

sf::Vector2f Renderer::projectObjectCoordinates(sf::Vector2f &coordinates) {

}

void Renderer::render(World &world) {
    sf::View view(
        sf::Vector2f(world.players[0]->position.x, world.players[0]->position.y),
        sf::Vector2f(100, 100)
    );

    sf::CircleShape spaceship(5.f, 3);

    window.clear();

    spaceship.setFillColor(sf::Color::Red);

    std::for_each(world.players.begin(), world.players.end(), [&spaceship, this] (auto it) {
        spaceship.setPosition(it->position);

        window.draw(spaceship);
    });

    window.setView(view);
    window.display();
}
