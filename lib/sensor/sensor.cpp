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

float Sensor::get_value()
{
    /*
    float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    int sensorValue = analogRead(A0);
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
    //-Replace the name "R0" with the value of R0 in the demo of First Test 
    ratio = RS_gas/R0;  // ratio = RS/R0
    */
    return ((analogRead(_pin))/1024*5.0);
}