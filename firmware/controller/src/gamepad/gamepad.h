#ifndef CONTROLLER_GAMEPAD_H
#define CONTROLLER_GAMEPAD_H

#include <Arduino.h>
#include <EspUsbHost.h>
#include "config.h"

class Gamepad {
    public:
        void begin();
    private:
        EspUsbHost usb;
        float applyDeadzone(float value);
        float normalizeAxis(int32_t value, int32_t logicalMin, int32_t logicalMax);
};

#endif