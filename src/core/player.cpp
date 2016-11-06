#include "./player.hpp"

#include <cmath>

float computeLinearParameterChange(
    const sf::Time &elapsedTime,
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
        * elapsedTime.asMilliseconds()
    );

    return current + absoluteChange * multiplier;
}

float Player::computeNewYaw(const sf::Time &elapsedTime, bool turnLeft, bool turnRight) const {
    return computeLinearParameterChange(elapsedTime, yawChangeSpeed, yaw, turnLeft, turnRight);
}

float Player::computeNewSpeed(const sf::Time &elapsedTime, bool forward, bool backward) const {
    const auto newSpeed = computeLinearParameterChange(
        elapsedTime,
        thrust,
        speed,
        backward,
        forward
    );

    if (fabs(newSpeed) > absoluteSpeedCap) {
        return absoluteSpeedCap * (newSpeed < 0 ? -1 : 1);
    } else {
        return newSpeed;
    }
}
