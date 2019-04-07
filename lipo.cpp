//
// Created by yura on 06.04.19.
//

#include <Arduino.h>
#include "lipo.h"

Lipo::Lipo(int low, int high, uint8_t analog_pin, int analog_read_max_voltage):
        m_low(low), m_high(high), m_analog_pin(analog_pin), m_max_voltage(analog_read_max_voltage)
{
    COTOMETR_LOG_ADD_DEBUG("Lipo inited");
}

Lipo::LEVEL Lipo::get_level() {
    COTOMETR_LOG_CLEAR();

    int digital_val = analogRead(m_analog_pin);

    long digital_min = map(m_low, 0, m_max_voltage, 0, 1023);
    long digital_max = map(m_high, 0, m_max_voltage, 0, 1023);

    return (LEVEL)map(digital_val, digital_min, digital_max, LEVEL_LOW, LEVEL_HIGH + 1);
}
