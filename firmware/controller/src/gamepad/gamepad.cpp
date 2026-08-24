#include <Gamepad/Gamepad.h>

// ESP32 as USB host to receive gamepad inputs
// https://github.com/tanakamasayuki/EspUsbHost/blob/main/examples/HID/EspUsbHostGamepad/EspUsbHostGamepad.ino

void Gamepad::begin() {
  usb.onDeviceConnected([](const EspUsbHostDeviceInfo& device) {
    Serial.print("connected: ");
    espUsbHostPrint(device);
  });

  usb.onDeviceDisconnected([](const EspUsbHostDeviceInfo& device) {
    Serial.print("disconnected: ");
    espUsbHostPrint(device);
  });

  usb.onGamepad([](const EspUsbHostGamepadEvent& event) {
    for (size_t i = 0; i < event.fieldCount; i++) {
      const EspUsbHostHIDFieldValue& field = event.fields[i];
    }
  });
}