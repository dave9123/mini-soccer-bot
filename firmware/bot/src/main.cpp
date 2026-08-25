#include <Arduino.h>
#include <Comm/Comm.h>
#include <Motor/Motor.h>

Motor motor;
Comm comm;

void setup() {
  motor.begin();
  comm.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}
