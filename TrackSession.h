#pragma once
#include <vector>
#include <string>
#include <iostream>

// Contains float s1,s2,s3 , float total
struct SectorTime {
    float s1, s2, s3;
    float total;

    // Calc total time (fastest possible time)
    void calcTotal() {
        this->total = this->s1 + this->s2 + this->s3;
    }

};

// Contains int num, SectorTime time, bool isValid
struct Lap {
    int num;
    SectorTime time;
    bool isValid; // check if lap is a valid lap (no shortcuts)
};

class TrackSession {
    std::string trackName; // name of track
    Lap latestLap;         // last lap
    Lap fastestLap;        // fastest (valid) lap

    SectorTime fastestSectors; // fastest sectors

    std::vector<Lap> allLaps;

public:
    explicit TrackSession(const std::string& trackName);

    // Add a Lap struct, returns whether new lap is fastest lap
    [[nodiscard]] bool addLap(Lap newLap);

    // get laps as Lap struct
    [[nodiscard]] Lap getFastestLap() const;
    [[nodiscard]] Lap getLatestLap() const;
    [[nodiscard]] int getTotalLaps() const;
    [[nodiscard]] const std::vector<Lap>& getAllLaps() const;

    // gets sector times including fastest possible lap
    [[nodiscard]] SectorTime getFastestSectors() const;

    // Get the trend from the last x laps (Using Linear Regression)
    [[nodiscard]] float getTrend(int x = 5) const;
};
