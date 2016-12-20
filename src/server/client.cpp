#include "./client.hpp"

bool Client::validateTimestamp(sf::Int32 timestamp) const {
    return timestamp > lastRecordedTimestamp;
}
