#include <Comm/Comm.h>


ControlPacket Comm::latestPacket;
bool Comm::newData = false;

void Comm::onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  if (!len == sizeof(ControlPacket)) {
    return;
  };

  memcpy(&latestPacket, incomingData, len);
  newData = true;
}

void Comm::begin() {
  // ESP-NOW implementation from https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println(F("ESPNOW init failed"));
    return;
  }

  esp_now_register_recv_cb(onDataRecv);
}