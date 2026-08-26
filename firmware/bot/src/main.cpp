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
  if (Comm::newData) {
    motor.drive(comm.latestPacket.moveY, comm.latestPacket.turnX);
  }
}
