#include <Comm/Comm.h>


void Comm::begin() {
  // ESP-NOW implementation from https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESPNOW init failed");
    return;
  }
}

void Comm::sendControls() {
  
}