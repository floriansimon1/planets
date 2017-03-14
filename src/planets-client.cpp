#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "./client/client-application.hpp"
#include "./graphics/renderer.hpp"

using namespace std::chrono_literals;

int main(void) {
    sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    ClientApplication application(window);

    std::cout << ">> PLANETS (client)" << std::endl;

    while (!application.shouldExit()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                application.requestExit();
            }

            std::this_thread::sleep_for(500ms);
        }
    }

    application.awaitTermination();

    window.close();

    return EXIT_SUCCESS;
}
