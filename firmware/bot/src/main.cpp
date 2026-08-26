#include <Arduino.h>
#include <Comm/Comm.h>
#include <Motor/Motor.h>

#include "config.h"

Motor motor;
Comm comm;

void setup() {
  motor.begin();
  comm.begin();
}

void loop() {
  if (Comm::newData) {
    if (comm.latestPacket.robotId == Config::ROBOT_ID)
      motor.drive(comm.latestPacket.moveY, comm.latestPacket.turnX);
  }
}
