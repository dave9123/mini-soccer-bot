#ifndef CONTROLLER_GAMEPAD_H
#define CONTROLLER_GAMEPAD_H

#include <Arduino.h>
#include <EspUsbHost.h>

class Gamepad {
    public:
        void begin();
    private:
        EspUsbHost usb;
};

#endif