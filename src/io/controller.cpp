#include "./controller.hpp"

#include <SFML/Graphics.hpp>

bool Controller::turnLeft() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool Controller::turnRight() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool Controller::accelerateBackward() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

bool Controller::accelerate() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}
