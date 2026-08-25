#include <Motor/Motor.h>

void Motor::begin() {
    ledcSetup();
    ledcAttachPin(Config::MOTOR_DRV1_LPWM, 20000);
    ledcAttachPin(Config::MOTOR_DRV1_RPWM, 20000);
    ledcAttachPin(Config::MOTOR_DRV2_LPWM, 20000);
    ledcAttachPin(Config::MOTOR_DRV2_RPWM, 20000);
}