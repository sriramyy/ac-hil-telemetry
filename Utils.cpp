#include "Utils.h"
#include <sstream>
#include <cmath>
#include <tuple>

namespace Utils {

    // Format any lap time (enter in float)
    std::string formatLapTime(float totalSeconds) {
        if (totalSeconds<=0 || totalSeconds>100000) return "--:--.---";

        int minutes = static_cast<int>(totalSeconds)/60;
        int seconds = static_cast<int>(totalSeconds)%60;
        int millis = static_cast<int>((totalSeconds - std::floor(totalSeconds)) * 1000);

        std::stringstream ss;
        ss << minutes << ":" << seconds << "." << millis;
        return ss.str();
    }

    // Format the Latest (last) lap time
    std::string formatLatestLapTime(const TrackSession& session) {
        return formatLapTime(session.getLatestLap().time.total);
    }

    // Format the Fastest Possible lap time (best sector times)
    std::string formatFastestPossibleLapTime(const TrackSession& session) {
        return formatLapTime(session.getFastestSectors().total);
    }

    // Format the Fastest lap time (actual fastest full lap time)
    std::string formatFastestLapTime(const TrackSession& session) {
        return formatLapTime(session.getFastestLap().time.total);
    }

    // Find delta between the Fastest lap and Fastest (sector) possible lap time
    float findFastestDelta(const TrackSession& session) {
        return session.getFastestLap().time.total - session.getFastestSectors().total;
    }
}
