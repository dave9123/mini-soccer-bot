#ifndef BOT_CONFIG_H
#define BOT_CONFIG_H

#include <Arduino.h>

namespace Config {
    constexpr uint8_t MOTOR_DRV1_RPWM = GPIO_NUM_0;
    constexpr uint8_t MOTOR_DRV1_LPWM = GPIO_NUM_1;
    constexpr uint8_t MOTOR_DRV2_RPWM = GPIO_NUM_2;
    constexpr uint8_t MOTOR_DRV2_LPWM = GPIO_NUM_3;

    constexpr uint8_t PWM_FREQ = 20000;
    static constexpr uint8_t PWM_RESOLUTION = 8;
    static constexpr int PWM_MAX = (1 << PWM_RESOLUTION) - 1;
}

#endif