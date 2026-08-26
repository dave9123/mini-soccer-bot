#ifndef CONTROLLER_GAMEPAD_H
#define CONTROLLER_GAMEPAD_H

#include <Arduino.h>
#include <EspUsbHost.h>
#include "config.h"

#include <Comm/Comm.h>

class Gamepad {
    public:
        void begin();
        void update();
    private:
        EspUsbHost usb;
        Comm comm;
        ControlPacket packet;
        
        int16_t axisToPWM(int32_t value, int32_t logicalMin, int32_t logicalMax);
};

#endif