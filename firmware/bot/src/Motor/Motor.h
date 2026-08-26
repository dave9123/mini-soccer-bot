#ifndef BOT_MOTOR_H
#define BOT_MOTOR_H

#include <Arduino.h>
#include "config.h"

class Motor {
    public:
        void begin();
        void drive(int16_t moveY, int16_t turnX);
};

#endif