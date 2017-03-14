#include <cmath>

#include "./player.hpp"
#include "../math/angles.hpp"
#include "../math/vector2.hpp"

float computeLinearParameterChange(
    sf::Int32 elapsedTime,
    float parameterChangeDeltaPerSecond,
    float current,
    bool decrease,
    bool increase
) {
    const auto multiplier = (
        ((decrease) ? -1.f : 0.f)
        + ((increase) ? 1.f : 0.f)
    );

    if (!multiplier) {
        return current;
    }

    const auto absoluteChange = (
        (parameterChangeDeltaPerSecond / 1000.f)
        * elapsedTime
    );

    return current + absoluteChange * multiplier;
}

float Player::computeNewYaw(sf::Int32 elapsedTime, bool turnLeft, bool turnRight) const {
    return computeLinearParameterChange(elapsedTime, yawChangeSpeed, yaw, turnLeft, turnRight);
}

sf::Vector2f Player::computeNewInertia(
    sf::Int32 elapsedTime,
    bool forward,
    bool backward,
    sf::Vector2f &inertia,
    float yaw
) const {
    const auto thrustNorm = computeLinearParameterChange(
        elapsedTime,
        thrust,
        0,
        backward,
        forward
    );

    const auto yawInRadians = degreesToRadians(yaw);

    const sf::Vector2f thrustVector(
        thrustNorm * cos(yawInRadians),
        thrustNorm * sin(yawInRadians)
    );

    const auto newInertia     = inertia + thrustVector;
    const auto newInertiaNorm = norm(newInertia);

    if (newInertiaNorm > speedCap) {
        return normalize(newInertia) * speedCap;
    } else {
        return newInertia;
    }
}

sf::Vector2f Player::computeNewPosition(
    sf::Int32 elapsedTime,
    const sf::Vector2f &position,
    const sf::Vector2f &inertia,
    const sf::Vector2f &worldDimensions
) const {
    const auto inertiaNorm = norm(inertia);

    const auto moveVector = normalize(inertia) * computeLinearParameterChange(
        elapsedTime,
        inertiaNorm,
        0,
        false,
        true
    );

    const auto potentiallyOffLimitsPosition = position + moveVector;

    auto x = potentiallyOffLimitsPosition.x;
    auto y = potentiallyOffLimitsPosition.y;

    if (x < 0.f) {
        x += worldDimensions.x;
    } else if (x > worldDimensions.x) {
        x -= worldDimensions.x;
    }

    if (y < 0.f) {
        y += worldDimensions.y;
    } else if (y > worldDimensions.y) {
        y -= worldDimensions.y;
    }

    return sf::Vector2f(x, y);
}

Player Player::move(sf::Int32 elapsedTime, const World &world, const ControllerState &controller) {
    Player updatedPlayer(*this);

    updatedPlayer.yaw = computeNewYaw(
        elapsedTime,
        controller.turnLeft(),
        controller.turnRight()
    );

    updatedPlayer.inertia = computeNewInertia(
        elapsedTime,
        controller.accelerate(),
        controller.accelerateBackward(),
        inertia,
        yaw
    );

    updatedPlayer.position = computeNewPosition(
        elapsedTime,
        position,
        inertia,
        world.dimensions
    );

    return updatedPlayer;
}
