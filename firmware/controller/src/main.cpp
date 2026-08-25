#include <Arduino.h>
#include <Gamepad/Gamepad.h>
#include <Comm/Comm.h>


Gamepad gamepad;
Comm comm;

void setup() {
  Serial.begin(115200);

  gamepad.begin();
  comm.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}
