#ifndef HEADER_SENSOR
#define HEADER_SENSOR

#include <Arduino.h>

constexpr uint8_t SENSOR_PIN = 36;

class Sensor {
public:
    Sensor();
    void init(const uint8_t pin);
    float get_value();
private:
    uint8_t _pin;
};

#endif // HEADER_SENSOR