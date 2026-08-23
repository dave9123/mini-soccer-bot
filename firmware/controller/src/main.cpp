#include <Arduino.h>
#include <EspUsbHost.h>
#include <WiFi.h>
#include <esp_now.h>

EspUsbHost usb;

void onDataSent(const uint8_t, *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast packet status:\t"); // \r goes to new line, \t adds tab (spacing)
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Failed");
}


void setup() {
  Serial.begin(115200);

  usb.onDeviceConnected([](const EspUsbHostDeviceInfo &device) {
    Serial.print("connected: ");
    espUsbHostPrint(device);
  });

  usb.onDeviceDisconnected([](const EspUsbHostDeviceInfo &device) {
    Serial.print("disconnected: ");
    espUsbHostPrint(device);
  });

  usb.onGamepad([](const EspUsbHostGamepadEvent &event) {
    // handle input
  });

  // ESP-NOW implementation from https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESPNOW init is being ahh");
    return;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
