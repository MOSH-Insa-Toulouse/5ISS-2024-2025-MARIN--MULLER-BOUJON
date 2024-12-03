#ifndef HEADER_SENSOR
#define HEADER_SENSOR

#include <Arduino.h>

constexpr uint8_t SENSOR_PIN = 34;
constexpr float R0 = 0.8;

class Sensor {
public:
    Sensor();
    void init(const uint8_t pin);
    float get_analog();
    float get_RSR0();
private:
    uint8_t _pin;
};

#endif // HEADER_SENSOR