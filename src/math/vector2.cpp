#include <cmath>

#include "./vector2.hpp"

float norm(const sf::Vector2f &vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f normalize(const sf::Vector2f &vector) {
    auto n = norm(vector);

    if (n == 0.f) {
        return vector;
    } else {
        return sf::Vector2f(vector.x / n, vector.y / n);
    }
}
