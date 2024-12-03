#include "sensor.hpp"
#include <Arduino.h>

Sensor::Sensor()
{}

void Sensor::init(const uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH);
}

float Sensor::get_analog()
{
    return (static_cast<float>(analogRead(_pin))/(1<<12))*3.3f;
}

// Normally should be 5V, but the ADC can only see up to 3.3 on 12 bits
float Sensor::get_RSR0()
{
    float sensor_volt=(static_cast<float>(analogRead(_pin))/(1<<12))*3.3f;
    float RS_gas = (3.3-sensor_volt)/sensor_volt;
    return RS_gas/R0;
}