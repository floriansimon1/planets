#include <algorithm>

#include "../boilerplate/collection-window.hpp"
#include "../boilerplate/find-index-right.hpp"
#include "../boilerplate/take-until.hpp"
#include "../boilerplate/for-each.hpp"
#include "../boilerplate/reduce.hpp"
#include "../boilerplate/clamp.hpp"
#include "../boilerplate/tail.hpp"
#include "./frame.hpp"

using InputHistoryWindow = CollectionWindow<decltype(InputHistory::history)>;

InputHistoryWindow getControllerStatesBefore(sf::Int32 timestamp, InputHistoryWindow inputWindow) {
    return takeUntil([timestamp] (const auto &controllerState) {
        return controllerState.timestamp <= timestamp;
    }, inputWindow);
}

Frame Frame::next(sf::Int32 newTimestamp) {
    Frame nextFrame { world, players, newTimestamp };

    const auto maxDeltaT = newTimestamp - timestamp;
    auto deltaT          = timestep;
    auto totalDeltaT     = timestep;

    std::vector<InputHistoryWindow> inputs;

    // Gets iterators to the first input state for every player.
    std::transform(
        players.begin(),
        players.end(),
        inputs.begin(),

        [this, newTimestamp] (auto player) {
            auto start = findIndexRight([this] (auto &controllerState) {
                return controllerState.timestamp <= timestamp;
            }, player.inputHistory.history);

            InputHistoryWindow inputWindow(player.inputHistory.history, start, nullptr);

            return getControllerStatesBefore(newTimestamp, inputWindow);
        }
    );

    /*
    * Because I'm not a math guy, I won't risk myself trying
    * to come up with fancy formulas to predict changes at every
    * input change. Instead, I chose to advance the frame by
    * small steps, and to check for collisions at each and every
    * one of those single steps.
    */
    while (totalDeltaT <= maxDeltaT) {
        forEach([totalDeltaT, &inputs, maxDeltaT, this] (auto &player, auto i) {
            auto currentTimestamp = totalDeltaT + timestep;

            auto relevantInputs = getControllerStatesBefore(currentTimestamp, inputs[i]);

            if (relevantInputs.empty()) {
                return;
            }

            if (!std::distance(relevantInputs.begin(), relevantInputs.last())) {
                const auto stateTimestamp = relevantInputs.begin()->timestamp;

                /*
                * Moves the player based on one controller state.
                * The clamp() call is here because the controller
                * state can have been started after the beginning
                * of the timestep.
                */
                player = player.move(
                    clamp(timestep - stateTimestamp - totalDeltaT, 0, timestep),
                    world,
                    *relevantInputs.begin()
                );
            }

            // Moves the player based on more than one controller states.
            reduce(
                [&player, maxDeltaT, this]
                (auto &currentControllerState, auto &nextControllerState) {
                    auto dt = (
                        clamp(nextControllerState.timestamp, 0, maxDeltaT)
                        - currentControllerState.timestamp
                    );

                    /*
                    * Same as above, the controller state can have been started
                    * after the beginning of the current timestep.
                    *
                    * TODO0
                    */

                    player = player.move(dt, world, currentControllerState);

                    return nextControllerState;
                },

                *relevantInputs.begin(),
                tail(relevantInputs)
            );
        }, nextFrame.players);

        // Loop iterator increment.
        if (totalDeltaT == maxDeltaT) {
            break;
        } else if (totalDeltaT + timestep > maxDeltaT) {
            deltaT      = maxDeltaT - totalDeltaT;
            totalDeltaT = maxDeltaT;
        } else {
            totalDeltaT += timestep;
        }
    }

    return nextFrame;
}
