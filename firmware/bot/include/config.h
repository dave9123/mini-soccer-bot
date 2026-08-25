#ifndef BOT_CONFIG_H
#define BOT_CONFIG_H

#include <Arduino.h>

namespace Config {
    constexpr uint8_t MOTOR_DRV1_RPWM = GPIO_NUM_0;
    constexpr uint8_t MOTOR_DRV1_LPWM = GPIO_NUM_1;
    constexpr uint8_t MOTOR_DRV2_RPWM = GPIO_NUM_2;
    constexpr uint8_t MOTOR_DRV2_LPWM = GPIO_NUM_3;
}

#endif