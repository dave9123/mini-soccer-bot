#include <Gamepad/Gamepad.h>

float Gamepad::applyDeadzone(float value) {
  if (fabs(value) < Config::DEADZONE) { // fabs makes the value positive
    return 0.0f;
  }

  return (value - copysign(Config::DEADZONE, value)) / (1.0f - Config::DEADZONE); // copysign(x, y) returns value of x and sign of y
  // equation prevents output jumping from deadzone
}

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

      // USB HID specification
      // https://www.usb.org/sites/default/files/hut1_21_0.pdf
      // https://learn.microsoft.com/en-us/windows-hardware/drivers/hid/hid-usages

      if (field.usagePage == HID_USAGE_PAGE_DESKTOP) {
        if (field.usage == HID_USAGE_DESKTOP_X) {
          // left x joystick (?)
        } else if (field.usage == HID_USAGE_DESKTOP_Y) {
          // left y joystick (?)
        } else if (field.usage == HID_USAGE_DESKTOP_RX) {
          // right x joystick (?)
        }
      }
    }
  });
}