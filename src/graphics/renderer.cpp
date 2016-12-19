#include "./renderer.hpp"
#include "../client/states/play.hpp"

#include <algorithm>

sf::Vector2f flip(const sf::Vector2f &position, const sf::Vector2f &dimensions) {
    return dimensions - position;
}

Renderer::Renderer(sf::RenderWindow &w): window(w) {
    window.setFramerateLimit(60);
}

void Renderer::render(const ClientApplication &application) const {
    const auto &currentStep = static_cast<const ClientState&>(*application.getCurrentStep());

    if (!currentStep.isGameState()) {
        return;
    }

    const auto &world = static_cast<const Play&>(currentStep).world;

    const WorldSpace minimap(world.dimensions * 2.f);

    sf::View minimapView(sf::FloatRect(
        2.f * world.dimensions.x,
        2.f * world.dimensions.y,
        world.dimensions.x,
        world.dimensions.y
    ));

    sf::View worldView(
        flip(world.players[0].position, world.dimensions),
        sf::Vector2f(100.f, 100.f)
    );

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

        [&spaceship, &worldView, &minimapView, &minimap, &world, this] (auto player) {
            spaceship.setPosition(flip(player.position, world.dimensions));

            // -180.f => By default, the spaceship faces down instead of up.
            spaceship.rotate(player.yaw + 90.f - 180.f);

            window.setView(worldView);
            window.draw(spaceship);

            spaceship.rotate(-spaceship.getRotation());

            window.setView(minimapView);
            minimap.draw(window, spaceship);
        }
    );

    window.display();
}
