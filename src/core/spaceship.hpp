#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>

#include "./world.hpp"
#include "./entity.hpp"
#include "../input/input-history.hpp"

struct Player: Entity {
    InputHistory inputHistory;

    std::string name;

    // In units/s.
    sf::Vector2f inertia;

    // In degrees (angle to the right segment of an horizontal line).
    float yaw;

    // In units/s-2.
    static const float thrust = 300.f;

    // In degrees/s.
    static const float yawChangeSpeed = 180.f;

    // In units/s.
    static const float speedCap = 100.f;

    Player(): Entity(150.f, 150.f), inertia(0.f, 0.f), yaw(90.f) {}

    float computeNewYaw(sf::Int32 elapsedTime, bool turnLeft, bool turnRight) const;

    sf::Vector2f computeNewInertia(
        sf::Int32 elapsedTime,
        bool forward,
        bool backward,
        sf::Vector2f &inertia,
        float yaw
    ) const;

    sf::Vector2f computeNewPosition(
        sf::Int32 elapsedTime,
        const sf::Vector2f &position,
        const sf::Vector2f &inertia,
        const sf::Vector2f &worldDimensions
    ) const;

    Player move(sf::Int32 elapsedTime, const World &world, const ControllerState &state);
};

#endif
