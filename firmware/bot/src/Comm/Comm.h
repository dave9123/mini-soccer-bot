#ifndef BOT_COMM_H
#define BOT_COMM_H

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <Motor/Motor.h>

struct __attribute__((packed)) ControlPacket {
    uint8_t robotId;
    int16_t moveY;
    int16_t turnX;
    uint8_t buttons;
};

class Comm {
    public:
        void begin();
        void update();
        static bool newData;
        static ControlPacket latestPacket;

    private:
        static void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
};

#endif