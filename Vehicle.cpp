#include "Vehicle.h"
#include <tuple>

using namespace std;


Vehicle::Vehicle(const unsigned int redlineRpm) : rpm(0), gear(0), rlRpm(redlineRpm), speed(0) {}

void Vehicle::setTelemetry(unsigned int rpm, unsigned int gear, float speed) {
    this->rpm = rpm;
    this->gear = gear;
    this->speed = speed;
}

void Vehicle::setTelemetry(const TelemetryData data) {
    this->rpm = data.rpm;
    this->gear = data.gear;
    this->speed = data.speed;
}

unsigned int Vehicle::getRpm() const {
    return rpm;
}

unsigned int Vehicle::getGear() const {
    return gear;
}

float Vehicle::getSpeed() const {
    return speed;
}

TelemetryData Vehicle::getTelemetry() const {
    TelemetryData data{rpm, gear, speed};
    return data;
}

void Vehicle::setRedline(unsigned int redlineRpm) {
    rlRpm = redlineRpm;
}

unsigned int Vehicle::getRedline() const {
    return rlRpm;
}
