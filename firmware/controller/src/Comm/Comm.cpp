#include <Comm/Comm.h>


void Comm::begin() {
  // ESP-NOW implementation from https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println(F("ESPNOW init failed"));
    return;
  }

  memcpy(peerInfo.peer_addr, Config::broadcastAddress, 6); // memcpy dump to memory, why not peerInfo.peer_addr = address tho?
  peerInfo.channel = Config::broadcastChannel;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void Comm::sendControls(const ControlPacket& packet) {
  esp_err_t result = esp_now_send(Config::broadcastAddress, (uint8_t *) &packet, sizeof(packet));

  if (result != ESP_OK) {
    Serial.println(F("Failed to send data"));
  }
}