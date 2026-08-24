#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>


void setup() {
  Serial.begin(115200);

  

  // ESP-NOW implementation from https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESPNOW init failed");
    return;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
