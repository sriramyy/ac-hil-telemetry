#pragma once
#include <tuple>

struct TelemetryData {
    unsigned int rpm;
    unsigned int gear;
    float speed;
};

class Vehicle {
    unsigned int rpm;     // RPM Value
    unsigned int gear;    // Gear the car is in
    float speed;          // MPH Speed

    unsigned int rlRpm;   // Vehicle-Specific Red line RPM (Shift Advised)

public:
    explicit Vehicle(unsigned int redlineRpm);

    // Sets the telemetry data
    void setTelemetry(unsigned int rpm, unsigned int gear, float speed);
    void setTelemetry(TelemetryData data);

    // Getter Functions
    [[nodiscard]] unsigned int getRpm() const;
    [[nodiscard]] unsigned int getGear() const;
    [[nodiscard]] float getSpeed() const;

    // Returns all telemetry data in TelemetryData struct
    [[nodiscard]] TelemetryData getTelemetry() const;

    // Red line functions
    void setRedline(unsigned int redlineRpm);
    [[nodiscard]] unsigned int getRedline() const;
};