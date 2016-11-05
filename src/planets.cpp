#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "./graphics/renderer.hpp"
#include "./io/controller.hpp"

int main(void) {
    World            world;
    sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    Controller controller(world.players[0]);
    Renderer   renderer(window);

    std::vector<Controller*> controllers;

    controllers.push_back(&controller);

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (
                event.type == sf::Event::KeyPressed
                && event.key.code == sf::Keyboard::Escape
            ) {
                window.close();
            }
        }

        world.makeNextFrame(controllers);

        renderer.render(world);
    }

    return EXIT_SUCCESS;
}
