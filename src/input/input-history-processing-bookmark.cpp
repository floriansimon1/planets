#include "./input-history-processing-bookmark.hpp"
#include "../boilerplate/remove-in.hpp"

InputHistoryProcessingBookmark::InputHistoryProcessingBookmark(InputHistory &h):
    InputHistoryBookmark(h)
{
}

std::list<ControllerState> InputHistoryProcessingBookmark::getHistoryToProcess(sf::Int32 timestamp) const {
    if (!bookmark) {
        return inputHistory.history;
    }

    const auto &lastComputationInfo = bookmark.value();

    std::list<ControllerState> toProcess(lastComputationInfo.iterator, inputHistory.history.end());

    if (toProcess.size()) {
        const auto &firstStateIterator = toProcess.begin();
        const auto shortenedTimestamp  = lastComputationInfo.timestamp + 1;

        const auto &firstState = *firstStateIterator;

        *firstStateIterator = ControllerState(
            shortenedTimestamp > firstState.timestamp ? shortenedTimestamp : firstState.timestamp,
            firstState
        );
    }

    removeIn(toProcess, [timestamp] (const auto &state) {
        return state.timestamp >= timestamp;
    });

    return toProcess;
}
