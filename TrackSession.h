#pragma once
#include <vector>
#include <string>

struct Lap {
    int num;
    float time;
};

class TrackSession {
    std::string trackName; // name of track
    Lap latestLap;         // last lap
    Lap fastestLap;        // fastest lap

    std::vector<Lap> allLaps;

public:
    explicit TrackSession(const std::string& trackName);

    // Add a Lap struct, returns whether new lap is fastest lap
    [[nodiscard]] bool addLap(Lap newLap);

    [[nodiscard]] Lap getFastestLap() const;
    [[nodiscard]] Lap getLatestLap() const;
    [[nodiscard]] int getTotalLaps() const;
    [[nodiscard]] const std::vector<Lap>& getAllLaps() const;
};
