#ifndef CONTROLLER_COMM_H
#define CONTROLLER_COMM_H

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include "config.h"

struct __attribute__((packed)) ControlPacket {
    uint8_t robotId = Config::ROBOT_ID;
    int16_t moveY;
    int16_t turnX;
    uint8_t buttons;
};

class Comm {
    public:
        void begin();
        void sendControls(const ControlPacket& packet);

    private:
        esp_now_peer_info_t peerInfo;
};

#endif