#include "TrackSession.h"
#include <limits>
#include <vector>

TrackSession::TrackSession(const std::string& trackName) : trackName(trackName) {
    fastestLap.time = std::numeric_limits<float>::max();
    fastestLap.num = 0;

    latestLap.time = 0;
    latestLap.num = 0;
}

bool TrackSession::addLap(Lap newLap) {
    // add to total laps
    allLaps.emplace_back(newLap);
    // make new latest lap
    latestLap = newLap;

    if (newLap.time < fastestLap.time) {
        // fastest lap
        fastestLap = newLap;
        return true;
    }
    return false;
}

Lap TrackSession::getFastestLap() const {
    return fastestLap;
}

Lap TrackSession::getLatestLap() const {
    return latestLap;
}

int TrackSession::getTotalLaps() const {
    return static_cast<int>(allLaps.size());
}

const std::vector<Lap>& TrackSession::getAllLaps() const {
    return allLaps;
}