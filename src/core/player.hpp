#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <memory>

#include <SFML/System.hpp>

#include "entity.hpp"

struct Player: Entity {
    sf::Vector2<float> direction;

    // In units/s.
    float speed;

    // In degrees.
    float yaw;

    // In degrees/s.
    const float yawChangeSpeed = 180.f;

    // In units/s-2.
    const float thrust = 15.f;

    // In units/s.
    const float absoluteSpeedCap = 15.f;

    Player(): Entity(500.f, 500.f), direction(0.f, 0.f), speed(0.f), yaw(0.f) {}

    float computeNewYaw(const sf::Time &elapsedTime, bool turnLeft, bool turnRight) const;
    float computeNewSpeed(const sf::Time &elapsedTime, bool forward, bool backward) const;
};

#endif
