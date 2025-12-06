#include "TrackSession.h"
#include <limits>
#include <vector>
#include "Utils.h"

TrackSession::TrackSession(const std::string& trackName) : trackName(trackName) {
    fastestLap.time.total = std::numeric_limits<float>::max();
    fastestLap.time.s1 = std::numeric_limits<float>::max();
    fastestLap.time.s2 = std::numeric_limits<float>::max();
    fastestLap.time.s3 = std::numeric_limits<float>::max();
    fastestLap.num = 0;

    latestLap.time.total = 0;
    latestLap.time.s1 = 0;
    latestLap.time.s2 = 0;
    latestLap.time.s3 = 0;
    latestLap.num = 0;

    fastestSectors.s1 = std::numeric_limits<float>::max();
    fastestSectors.s2 = std::numeric_limits<float>::max();
    fastestSectors.s3 = std::numeric_limits<float>::max();
    fastestSectors.total = std::numeric_limits<float>::max();
}

bool TrackSession::addLap(Lap newLap) {
    // add to total laps
    allLaps.emplace_back(newLap);
    // make new latest lap
    latestLap = newLap;

    if (!newLap.isValid) {
        // if lap is not valid don't check for fastest sectors / lap.
        return false;
    }
    if (newLap.time.total < fastestLap.time.total) {
        // fastest lap
        fastestLap = newLap;
        return true;
    }

    // check for fastest sector times
    if (newLap.time.s1 < fastestSectors.s1) {
        fastestSectors.s1 = newLap.time.s1;
    }
    if (newLap.time.s2 < fastestSectors.s2) {
        fastestSectors.s2 = newLap.time.s2;
    }
    if (newLap.time.s3 < fastestSectors.s3) {
        fastestSectors.s3 = newLap.time.s3;
    }

    // recalc fastest possible time
    fastestSectors.calcTotal();

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

SectorTime TrackSession::getFastestSectors() const {
    return fastestSectors;
}

float TrackSession::getTrend(int x) const {
    // implement linear regression

    if (allLaps.empty() || x < 2) return 0.0f;
    std::vector<float> validTimes;

    for (auto it = allLaps.rbegin(); it != allLaps.rend(); ++it) {
        if (validTimes.size() >= x) break; // stop if we have x laps
        if (it->isValid) {
            validTimes.push_back(it->time.total);
        }
    }

    int n = static_cast<int>(validTimes.size());
    float sumX = 0.0f;
    float sumY = 0.0f;
    float sumXY = 0.0f;
    float sumX2 = 0.0f;

    for (int i = 0; i < n; ++i) {
        float y = validTimes[n - 1 - i];
        float x_val = static_cast<float>(i);

        sumX += x_val;
        sumY += y;
        sumXY += (x_val * y);
        sumX2 += (x_val * x_val);
    }

    float numerator = (n * sumXY) - (sumX * sumY);
    float denominator = (n * sumX2) - (sumX * sumX);

    if (denominator == 0) return 0.0f;

    return numerator / denominator;
}
