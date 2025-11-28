#pragma once
#include <vector>
#include <string>

// TODO: add sector time support
// struct SectorTime {
//     float s1, s2, s3;
// };

struct Lap {
    int num;
    // SectorTime time;
    float time;
    bool isValid; // check if lap is a valid lap (no shortcuts)
};

class TrackSession {
    std::string trackName; // name of track
    Lap latestLap;         // last lap
    Lap fastestLap;        // fastest (valid) lap

    std::vector<Lap> allLaps;

public:
    explicit TrackSession(const std::string& trackName);

    // Add a Lap struct, returns whether new lap is fastest lap
    [[nodiscard]] bool addLap(Lap newLap);

    [[nodiscard]] Lap getFastestLap() const;
    [[nodiscard]] Lap getLatestLap() const;
    [[nodiscard]] int getTotalLaps() const;
    [[nodiscard]] const std::vector<Lap>& getAllLaps() const;

    // Get the trend from the last x laps (Using Linear Regression)
    [[nodiscard]] float getTrend(int x) const;
};
