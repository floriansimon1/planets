#include "./renderer.hpp"
#include "./world-space.hpp"

#include <algorithm>

Renderer::Renderer(sf::RenderWindow &w): window(w) {
    window.setFramerateLimit(60);
}

void Renderer::render(World &world) const {
    const WorldSpace minimap(world.dimensions * 2.f);

    sf::View minimapView(sf::FloatRect(
        2.f * world.dimensions.x,
        2.f * world.dimensions.y,
        world.dimensions.x,
        world.dimensions.y
    ));

    sf::View worldView(world.players[0]->position, sf::Vector2f(100, 100));

    sf::RectangleShape minimapBackground(world.dimensions);
    sf::CircleShape    spaceship(5.f, 3);

    // Center of rotation.
    spaceship.setOrigin(5.f, 5.f);

    // Makes the front of the spaceship stand out.
    spaceship.scale(0.8f, 1.3f);

    spaceship.setFillColor(sf::Color::Red);
    minimapBackground.setFillColor(sf::Color(0, 0, 128, 200));

    window.clear();

    minimapView.setViewport(sf::FloatRect(0.7, 0.8, 0.25, 0.15));

    window.setView(minimapView);
    minimapBackground.setPosition(0.f, 0.f);
    minimap.draw(window, minimapBackground);

    std::for_each(
        world.players.begin(),
        world.players.end(),

        [&spaceship, &worldView, &minimapView, &minimap, this] (auto player) {
            spaceship.setPosition(player->position);

            spaceship.rotate(player->yaw);

            window.setView(worldView);
            window.draw(spaceship);

            spaceship.rotate(-spaceship.getRotation());

            window.setView(minimapView);
            minimap.draw(window, spaceship);
        }
    );

    window.display();
}
