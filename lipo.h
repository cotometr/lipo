#pragma once

#include "../log/log.h"

class Lipo
{
public:
    /**
     * @param low voltage level for the discharged battery in 1Volt * 100
     * @param high voltage level for the charged battery
     * @param analog_pin the pin for reading the voltage level
     * @param analog_read_max_voltage the max milivoltage input of the analog pin
     */
    explicit Lipo(int low, int high, uint8_t analog_pin, int analog_read_max_voltage) ;

    enum LEVEL
    {
        LEVEL_LOW,
        LEVEL_MIDDLE,
        LEVEL_HIGH
    };

    LEVEL get_level();

    COTOMETR_LOG_GET_DEBUG();
private:
    COTOMETR_LOG_CREATE_DEBUG();

    uint8_t m_analog_pin;
    int m_low;
    int m_high;
    const int m_max_voltage;
};