//
// Created by yura on 06.04.19.
//

#include <Arduino.h>
#include "lipo.h"

Lipo::Lipo(int low, int high, uint8_t analog_pin, int analog_read_max_voltage):
        m_low(low), m_high(high), m_analog_pin(analog_pin), m_max_voltage(analog_read_max_voltage)
{
    COTOMETR_LOG_ADD_DEBUG("Lipo inited: low = " + String(low) + " High = " + String(high)
                           + " pin = " + String(analog_pin) + " max pin voltage = " + String(m_max_voltage));
}

Lipo::LEVEL Lipo::get_level() {
    COTOMETR_LOG_CLEAR();

    int digital_val = analogRead();
    COTOMETR_LOG_ADD_DEBUG("Read voltage = " + String(digital_val) + "voltage = "
                           + String((digital_val * m_max_voltage) / 1023));

    long digital_min = map(m_low, 0, m_max_voltage, 0, 1023);
    long digital_max = map(m_high, 0, m_max_voltage, 0, 1023);

    return (LEVEL)map(digital_val, digital_min, digital_max, LEVEL_LOW, LEVEL_HIGH + 1);
}

float Lipo::get_voltage() {
    COTOMETR_LOG_CLEAR();

    float digital_val = analogRead();

    float voltage = digital_val * 3.3f / 512.0f;

    return voltage;
}

int compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;

    return 0;
}

float Lipo::analogRead() {
    int max = 0;
    constexpr int iter_count = 30;

    for (int i = 0; i < iter_count; i++) {
        int curr = ::analogRead(m_analog_pin);
        if (curr > max) {
            max = curr;
        }

        delay(50);
    }

    return max;
}
