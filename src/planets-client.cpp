#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "./client/client-application.hpp"
#include "./graphics/renderer.hpp"

int main(void) {
    ClientApplication application;

    sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    Renderer renderer(window);

    application.localPlayerName = "Paul";

    window.setFramerateLimit(200);

    std::cout << ">> PLANETS (client)" << std::endl;

    while (!application.shouldExit() && window.isOpen()) {
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

        application.process();

        renderer.render(state.world);
    }

    return EXIT_SUCCESS;
}
