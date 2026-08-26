#include <Gamepad/Gamepad.h>


int16_t Gamepad::axisToPWM(int32_t value, int32_t logicalMin, int32_t logicalMax) {
  float center = (logicalMin + logicalMax) /
                 2.0f;  // most likely (127 + (-127)) / 2.0f would be 0 / 2.0f, rather weird
  float halfRange = (logicalMax - logicalMin) /
                    2.0f;  // logically saying, if it's 127, -127, it'd be 254 / 2.0f eh?

  float normalized = constrain((value - center) / halfRange, -1.0f, 1.0f);

  // apply deadzone as some controllers manufacturers are ahh cheapskate
  if (fabs(normalized) < Config::DEADZONE) {  // fabs makes the value positive
    return 0.0f;
  }

  float noDeadzone = (normalized - copysign(Config::DEADZONE, normalized)) /
                     (1.0f - Config::DEADZONE);  // copysign(x, y) returns value of x and sign of y
  // equation prevents output jumping from deadzone

  return static_cast<int16_t>(
      noDeadzone * Config::DRV_PWM_MAX);  // int8_t only goes to 127, holy cow, rip unused allocated memory
}

// ESP32 as USB host to receive gamepad inputs
// https://github.com/tanakamasayuki/EspUsbHost/blob/main/examples/HID/EspUsbHostGamepad/EspUsbHostGamepad.ino

void Gamepad::begin() {
  usb.onDeviceConnected([](const EspUsbHostDeviceInfo& device) {
    Serial.print(F("connected: "));
    espUsbHostPrint(device);
  });

  usb.onDeviceDisconnected([](const EspUsbHostDeviceInfo& device) {
    Serial.print(F("disconnected: "));
    espUsbHostPrint(device);
  });

  usb.onGamepad([this](const EspUsbHostGamepadEvent& event) {
    for (size_t i = 0; i < event.fieldCount; i++) {
      const EspUsbHostHIDFieldValue& field = event.fields[i];

      // USB HID specification
      // https://www.usb.org/sites/default/files/hut1_21_0.pdf
      // https://learn.microsoft.com/en-us/windows-hardware/drivers/hid/hid-usages

      if (field.usagePage != HID_USAGE_PAGE_DESKTOP) {
        continue;
      }

      if (field.usage == HID_USAGE_DESKTOP_Y) {
        // left y joystick (?) -> go forward/backward
        packet.moveY = (int16_t)(Gamepad::axisToPWM(field.value, field.logicalMin, field.logicalMax));
      } else if (field.usage == HID_USAGE_DESKTOP_RX) {
        // right x joystick (?) -> turn left/right
        packet.turnX = (int16_t)(Gamepad::axisToPWM(field.value, field.logicalMin, field.logicalMax));
      } else if (field.usage == HID_USAGE_DESKTOP_DPAD_LEFT) {
        // r2 joystick (?) -> shoot
        if (field.value) {
          packet.buttons |= 0x01; // bitwise OR, set bit 1
        } else {
          packet.buttons &= ~0x01; // bitwise NOT -> AND, clear bit 1
        }
      }
    }
  });

  if (!usb.begin()) {
    Serial.printf("usb begin failed: %s", usb.lastErrorName());
  }
}

void Gamepad::update() {
  static uint32_t lastSend = 0;

  if (millis() - lastSend >= 20) {  // send every 20 ms
    lastSend = millis();

    comm.sendControls(packet);
  }
}