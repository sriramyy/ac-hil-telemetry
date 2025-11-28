#include "SerialBridge.h"
#include <algorithm>


uint8_t SerialBridge::calcLedOn(const Vehicle &myCar) const {
    auto redline = static_cast<float>(myCar.getRedline());
    auto startRpm = redline * SHIFT_POINT_START  ;
    auto rpm = static_cast<float>(myCar.getRpm());

    if (rpm < startRpm) return 0;

    float range = redline - startRpm;
    float progress = (rpm - startRpm) / range;

    int ledCount = static_cast<int>(progress * static_cast<float>(MAX_LEDS));

    return static_cast<uint8_t>(std::clamp(ledCount, 0, MAX_LEDS));
}

SerialBridge::SerialBridge() = default;

ArduinoPacket SerialBridge::encodePacket(const Vehicle &myCar) const {
    auto gear = static_cast<uint8_t>(myCar.getGear());

    return ArduinoPacket{0xFF, calcLedOn(myCar), gear, 0};
}
