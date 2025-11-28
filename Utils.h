#pragma once
#include "Vehicle.h"
#include "TrackSession.h"
#include <tuple>

namespace Utils {
    // Convert lap time from seconds to "MM:SS.MS"
    [[nodiscard]] std::string formatLapTime(float totalSeconds);

    // Convert last lap time from seconds to "MM:SS.MS"
    [[nodiscard]] std::string formatLatestLapTime(const TrackSession& session);

    // Convert fastest lap time from seconds to "MM:SS.MS"
    [[nodiscard]] std::string formatFastestLapTime(const TrackSession& session);

};
