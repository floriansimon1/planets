#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "./graphics/renderer.hpp"

int main(void) {
    World            world;
    sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    Renderer renderer(window);

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        renderer.render(world);
    }

    return EXIT_SUCCESS;
}
