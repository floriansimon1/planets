#include <cmath>
#include <chrono>

#include "./physical-parameters.hpp"
#include "../math/vector2.hpp"

using namespace std::chrono_literals;

struct Derivative {
    sf::Vector2f dPosition;
    sf::Vector2f dSpeed;
};

float updateAngle(const PhysicalParameters &state, const Movement &movement, std::chrono::milliseconds dt) {
    if (!movement.rotationMovement) {
        return state.angle;
    } else {
        const auto multiplier = movement.rotationMovement == Movement::left ? 1 : -1;

        return state.angle + dt.count() * multiplier * state.rotation;
    }
}

sf::Vector2f updateSpeed(
    const PhysicalParameters &state,
    float angle,
    const Movement &movement,
    std::chrono::milliseconds dt
) {
    if (!movement.thrustMovement) {
        return state.speed;
    } else {
        const auto multiplier = movement.thrustMovement == Movement::accelerate ? 1 : -1;

        const auto thrustNorm = dt.count() * multiplier * state.thrust;

        const sf::Vector2f thrustVector(
            thrustNorm * cos(angle),
            thrustNorm * sin(angle)
        );

        const auto uncappedSpeedVector = state.speed + thrustVector;

        if (norm(uncappedSpeedVector) > state.speedCap) {
            return state.speedCap.value() * normalize(uncappedSpeedVector);
        }

        return uncappedSpeedVector;
    }
}

Derivative getDerivative(
    const Movement &movement,
    const PhysicalParameters &state,
    const Derivative *input,
    std::chrono::milliseconds dt
) {
    auto position = state.position;
    auto speed    = state.speed;

    if (input != nullptr) {
        position.x += input->dPosition.x * dt.count();
        position.y += input->dPosition.y * dt.count();
        speed.x    += input->dSpeed.x * dt.count();
        speed.y    += input->dSpeed.y * dt.count();
    }

    const auto updatedAngle = updateAngle(state, movement, dt);

    return Derivative { state.speed, updateSpeed(state, updatedAngle, movement, dt) };
}

template<typename Getter>
sf::Vector2f getRk4Coefficient(
    const Getter &getter,
    const Derivative &k1,
    const Derivative &k2,
    const Derivative &k3,
    const Derivative &k4
) {
    return (getter(k1) + 2.f * (getter(k2) + getter(k3)) + getter(k4)) / 6.f;
}

// Integration using the RK4 method.
void PhysicalParameters::refresh(const Movement &movement, std::chrono::milliseconds dt) {
    const auto k1 = getDerivative(movement, *this, nullptr, 0ms);

    const auto k2 = getDerivative(movement, *this, &k1, dt / 2);

    const auto k3 = getDerivative(movement, *this, &k2, dt / 2);

    const auto k4 = getDerivative(movement, *this, &k3, dt / 2);

    // TODO: recalculate clamped angle, and clamp position.

    speed = (float) dt.count() * getRk4Coefficient(
        [] (const auto &derivative) {
            return derivative.dSpeed;
        },

        k1,
        k2,
        k3,
        k4
    );

    position = (float) dt.count() * getRk4Coefficient(
        [] (const auto &derivative) {
            return derivative.dPosition;
        },

        k1,
        k2,
        k3,
        k4
    );
}
