#ifndef CONTROLLER_COMM_H
#define CONTROLLER_COMM_H

#include <esp_now.h>
#include <WiFi.h>

struct ControlPacket {
    uint8_t robotId;

    int8_t moveY;
    int8_t turnX;

    uint8_t buttons;
    uint8_t sequence;
};

class Comm {
    public:
        void begin();
        void sendControls();
};

#endif