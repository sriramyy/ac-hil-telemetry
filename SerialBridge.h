#pragma once
#include <cstdint>
#include "Vehicle.h"

struct ArduinoPacket {
    uint8_t startMarker; // header 0xFF
    uint8_t rpmLedCount; // 0-8 LEDs on
    uint8_t gear;        // 0-9
    uint8_t flags;       //
};

class SerialBridge {
    const int MAX_LEDS = 8;
    const float SHIFT_POINT_START = 0.85; // shift lights start at 85% redline

    // helper function to calculate which LEDs should be on
    [[nodiscard]] uint8_t calcLedOn(const Vehicle& myCar) const;
public:
    SerialBridge();

    // function to send an Arduino Packet that has the rpm led count, gear, and any flags (if applicable)
    [[nodiscard]] ArduinoPacket encodePacket(const Vehicle& myCar) const;
};