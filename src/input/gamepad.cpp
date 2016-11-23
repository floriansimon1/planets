#include <SFML/Graphics.hpp>

#include "./gamepad.hpp"

bool Gamepad::turnLeft() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool Gamepad::turnRight() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool Gamepad::accelerateBackward() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

bool Gamepad::accelerate() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}
