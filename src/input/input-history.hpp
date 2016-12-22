#ifndef INPUT_HISTORY_HPP
#define INPUT_HISTORY_HPP

#include <SFML/System.hpp>
#include <vector>
#include <deque>

#include "../network/network.hpp"
#include "../input/controller-state.hpp"

struct InputHistory {
    Id                           lastDiscarded;
    Id                           lastProcessed;
    std::vector<ControllerState> history;

    std::vector<ControllerState>::iterator getStateIterator(Id stateId);
    void startBuffering(sf::Int32 timestamp, const Controller &initial);
    void bufferInput(sf::Int32 timestamp, const Controller &controller);
    const ControllerState& operator[](Id stateId);
    const ControllerState& getLastEntry() const;
    void discardUpTo(Id ackedId);
    void historyProcessed();

    protected:
        // For child classes only.
        virtual void beforeBufferingStarts(sf::Int32 timestamp) {};
};

#endif
