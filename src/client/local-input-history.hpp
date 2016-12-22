#ifndef LOCAL_INPUT_HISTORY_HPP
#define LOCAL_INPUT_HISTORY_HPP

#include "../input/input-history.hpp"

struct LocalInputHistory: InputHistory {
    sf::Int32 lastSentTime = 0;
    Id        lastSent     = 0;

    bool shouldSend(sf::Int32 timestamp);
    void historySent(sf::Int32 timestamp);

    protected:
        virtual void beforeBufferingStarts(sf::Int32 timestamp) override;
};

#endif
