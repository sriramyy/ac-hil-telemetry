#include "Utils.h"
#include <sstream>
#include <cmath>
#include <tuple>

namespace Utils {
    std::string formatLapTime(float totalSeconds) {
        if (totalSeconds<=0 || totalSeconds>100000) return "--:--.---";

        int minutes = static_cast<int>(totalSeconds)/60;
        int seconds = static_cast<int>(totalSeconds)%60;
        int millis = static_cast<int>((totalSeconds - std::floor(totalSeconds)) * 1000);

        std::stringstream ss;
        ss << minutes << ":" << seconds << "." << millis;
        return ss.str();
    }

    std::string formatLatestLapTime(const TrackSession& session) {
        return formatLapTime(session.getLatestLap().time);
    }

    std::string formatFastestLapTime(const TrackSession &session) {
        return formatLapTime(session.getFastestLap().time);
    }
}
