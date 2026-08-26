#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

namespace Config {
    // gamepad
    constexpr float DEADZONE = 0.08f;

    // comm
    constexpr uint8_t broadcastAddress[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    constexpr int broadcastChannel = 1;
    constexpr uint8_t ROBOT_ID = 1;
    
    // bot
    constexpr int8_t DRV_PWM_MAX = 255; // (1 << PWM_RESOLUTION = 8) - 1
}

#endif