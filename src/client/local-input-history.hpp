#ifndef LOCAL_INPUT_HISTORY_HPP
#define LOCAL_INPUT_HISTORY_HPP

#include "../input/input-history-transfer-bookmark.hpp"
#include "../input/input-history-processing-bookmark.hpp"

struct LocalInputHistory: InputHistory {
    InputHistory                   inputHistory;
    InputHistoryTransferBookmark   sendBookmark;
    InputHistoryProcessingBookmark processingBookmark;

    LocalInputHistory();
};

#endif
