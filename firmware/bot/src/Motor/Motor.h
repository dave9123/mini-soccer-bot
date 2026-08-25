#ifndef BOT_MOTOR_H
#define BOT_MOTOR_H

#include <Arduino.h>
#include "config.h"

class Motor {
    public:
        void begin();

    private:
        static constexpr uint32_t PWM_FREQ = 20000;
        static constexpr uint8_t PWM_RESOLUTION = 8;
        static constexpr int PWM_MAX = 255;
};



#endif